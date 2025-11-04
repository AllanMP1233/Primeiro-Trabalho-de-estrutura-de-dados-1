#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "fila.h"
#include "pilha.h"
#include "criarsvg.h"
#include "arena.h"

typedef struct {
    void *forma;
    char tipo;
    int id;
} FormaArena;

typedef struct {
    double x, y;
    double angulo;
    Pilha *esquerda;
    Pilha *direita;
    void *carga_disparo;
    char tipo_disparo;
} Disparador;

int main(int argc, char *argv[]){
    char *diretorio_entrada = ".";
    char *arquivo_geo = NULL;
    char *diretorio_saida = NULL;
    char *arquivo_qry = NULL;
    
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-e") == 0 && i + 1 < argc){
            diretorio_entrada = argv[++i];
        }
        else if(strcmp(argv[i], "-f") == 0 && i + 1 < argc){
            arquivo_geo = argv[++i];
        }
        else if(strcmp(argv[i], "-o") == 0 && i + 1 < argc){
            diretorio_saida = argv[++i];
        }
        else if(strcmp(argv[i], "-q") == 0 && i + 1 < argc){
            arquivo_qry = argv[++i];
        }
    }
    
    if(arquivo_geo == NULL || diretorio_saida == NULL){
        printf("Uso: %s -e <dir_entrada> -f <arquivo.geo> -o <dir_saida> [-q <arquivo.qry>]\n", argv[0]);
        return 1;
    }
    
    char caminho_geo[512], caminho_svg[512], caminho_txt[512];
    snprintf(caminho_geo, sizeof(caminho_geo), "%s/%s", diretorio_entrada, arquivo_geo);
    
    char nome_base[256];
    strcpy(nome_base, arquivo_geo);
    char *ponto = strrchr(nome_base, '.');
    if(ponto != NULL) *ponto = '\0';
    
    snprintf(caminho_svg, sizeof(caminho_svg), "%s/%s.svg", diretorio_saida, nome_base);
    snprintf(caminho_txt, sizeof(caminho_txt), "%s/%s.txt", diretorio_saida, nome_base);
    
    printf("=== PROCESSAMENTO INICIADO ===\n");
    printf("Arquivo GEO: %s\n", caminho_geo);
    printf("Arquivo SVG: %s\n", caminho_svg);
    printf("==============================\n\n");
    
    iniciasvg(caminho_svg, 800.0, 600.0);
    
    Fila *chao = criar_fila(1000);
    FormaArena *arena[1000];
    int num_formas_arena = 0;
    Disparador disparadores[100];
    int num_disparadores = 0;
    
    FILE *geo_file = fopen(caminho_geo, "r");
    if(geo_file == NULL){
        printf("ERRO: Não foi possível abrir %s\n", caminho_geo);
        return 1;
    }
    
    char linha[512];
    int formas_criadas = 0;
    
    while(fgets(linha, sizeof(linha), geo_file) != NULL){
        char comando;
        if(sscanf(linha, " %c", &comando) == 1){
            if(comando == 'c'){
                int id;
                double x, y, r;
                char corb[50], corp[50];
                if(sscanf(linha, " c %d %lf %lf %lf %s %s", &id, &x, &y, &r, corb, corp) == 6){
                    Circulo *circ = criarcirculo(id, x, y, r, corb, corp);
                    enfileirar(chao, circ);
                    FILE *f = fopen(caminho_svg, "a");
                    desenharcirculo(circ, f);
                    fclose(f);
                    formas_criadas++;
                }
            }
            else if(comando == 'r'){
                int id;
                double x, y, w, h;
                char corb[50], corp[50];
                if(sscanf(linha, " r %d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp) == 7){
                    Rectan ret = criarRetangulo(id, x, y, w, h, corb, corp);
                    enfileirar(chao, ret);
                    FILE *f = fopen(caminho_svg, "a");
                    desenhar_ret(ret, f);
                    fclose(f);
                    formas_criadas++;
                }
            }
            else if(comando == 'l'){
                int id;
                double x1, y1, x2, y2;
                char cor[50];
                if(sscanf(linha, " l %d %lf %lf %lf %lf %s", &id, &x1, &y1, &x2, &y2, cor) == 6){
                    Linha *lin = criarlinha(id, x1, y1, x2, y2, cor);
                    enfileirar(chao, lin);
                    formas_criadas++;
                }
            }
            else if(comando == 't'){
                int id;
                double x, y;
                char corb[50], corp[50], ancora, texto[256];
                if(sscanf(linha, " t %d %lf %lf %s %s %c %[^\n]", &id, &x, &y, corb, corp, &ancora, texto) >= 6){
                    Texto *txt = criartxt(id, x, y, texto, corb);
                    enfileirar(chao, txt);
                    formas_criadas++;
                }
            }
            else if(comando == 'p' && linha[1] == 'd'){
                int id;
                double x, y, angulo;
                if(sscanf(linha, " pd %d %lf %lf %lf", &id, &x, &y, &angulo) == 4){
                    disparadores[num_disparadores].x = x;
                    disparadores[num_disparadores].y = y;
                    disparadores[num_disparadores].angulo = angulo;
                    disparadores[num_disparadores].esquerda = criar_pilha();
                    disparadores[num_disparadores].direita = criar_pilha();
                    disparadores[num_disparadores].carga_disparo = NULL;
                    num_disparadores++;
                }
            }
        }
    }
    
    fclose(geo_file);
    printf("Formas no chão: %d\n", formas_criadas);
    printf("Disparadores criados: %d\n\n", num_disparadores);
    
    if(arquivo_qry != NULL){
        char caminho_qry[512];
        snprintf(caminho_qry, sizeof(caminho_qry), "%s/%s", diretorio_entrada, arquivo_qry);
        
        FILE *qry_file = fopen(caminho_qry, "r");
        FILE *txt_file = fopen(caminho_txt, "w");
        
        if(qry_file && txt_file){
            fprintf(txt_file, "=== RELATÓRIO DE EXECUÇÃO ===\n\n");
            
            int comandos = 0, disparos = 0, clones = 0, esmagadas = 0;
            double pontuacao = 0.0;
            
            while(fgets(linha, sizeof(linha), qry_file) != NULL){
                char cmd[10];
                if(sscanf(linha, " %s", cmd) == 1){
                    comandos++;
                    fprintf(txt_file, "Comando [%d]: %s", comandos, linha);
                    
                    if(strcmp(cmd, "lc") == 0){
                        int disp_id, forma_id;
                        char lado;
                        if(sscanf(linha, " lc %d %c %d", &disp_id, &lado, &forma_id) == 3){
                            fprintf(txt_file, "  → Carregador %c do disparador %d recebeu forma %d\n", lado, disp_id, forma_id);
                        }
                    }
                    else if(strcmp(cmd, "dsp") == 0){
                        disparos++;
                        fprintf(txt_file, "  → Disparo realizado!\n");
                    }
                    else if(strcmp(cmd, "calc") == 0){
                        fprintf(txt_file, "  → Calculando pontuação...\n");
                    }
                }
            }
            
            fprintf(txt_file, "\n=== ESTATÍSTICAS FINAIS ===\n");
            fprintf(txt_file, "Pontuação final: %.2lf\n", pontuacao);
            fprintf(txt_file, "Instruções executadas: %d\n", comandos);
            fprintf(txt_file, "Disparos: %d\n", disparos);
            fprintf(txt_file, "Formas esmagadas: %d\n", esmagadas);
            fprintf(txt_file, "Formas clonadas: %d\n", clones);
            
            fclose(txt_file);
            fclose(qry_file);
        }
    }
    
    finalizarsvg(caminho_svg);
    liberar_fila(chao);
    
    printf("=== PROCESSAMENTO CONCLUÍDO ===\n");
    printf("Arquivos gerados com sucesso!\n");
    
    return 0;
}
