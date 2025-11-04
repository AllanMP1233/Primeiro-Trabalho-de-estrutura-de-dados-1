#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "disparador.h"
#include "pilha.h"

typedef struct {
    double x, y;
    double angulo;
    Pilha *esquerda;
    Pilha *direita;
    void *carga_disparo;
    char tipo_disparo;
    int id;
} DisparadorStruct;

static DisparadorStruct disparadores[100];
static int num_disparadores = 0;

void criar_disparador(char *nomearqsvg, char *nomearqdisparador){
    FILE *saida = fopen(nomearqsvg, "a");
    if (saida == NULL) {
        perror("Erro ao abrir/criar arquivo svg");
        return;
    }
    fprintf(saida, "<!-- Início do arquivo DISPARADOR: %s -->\n", nomearqdisparador);
    fprintf(saida, "<!-- Arquivo DISPARADOR processado com sucesso -->\n");
    fprintf(saida, "<!-- Fim do arquivo DISPARADOR: %s -->\n", nomearqdisparador);
    fclose(saida);
}

int adicionar_disparador(int id, double x, double y, double angulo){
    if(num_disparadores >= 100) return -1;
    
    disparadores[num_disparadores].id = id;
    disparadores[num_disparadores].x = x;
    disparadores[num_disparadores].y = y;
    disparadores[num_disparadores].angulo = angulo;
    disparadores[num_disparadores].esquerda = criar_pilha();
    disparadores[num_disparadores].direita = criar_pilha();
    disparadores[num_disparadores].carga_disparo = NULL;
    disparadores[num_disparadores].tipo_disparo = '\0';
    
    return num_disparadores++;
}

bool carregar_forma(int disp_id, char lado, void *forma, char tipo){
    if(disp_id < 0 || disp_id >= num_disparadores) return false;
    
    if(lado == 'd' || lado == 'D'){
        empilhar(&disparadores[disp_id].direita, forma);
    } else if(lado == 'e' || lado == 'E'){
        empilhar(&disparadores[disp_id].esquerda, forma);
    } else {
        return false;
    }
    
    return true;
}

bool selecionar_carga(int disp_id, char lado){
    if(disp_id < 0 || disp_id >= num_disparadores) return false;
    
    if(disparadores[disp_id].carga_disparo != NULL){
        empilhar(&disparadores[disp_id].esquerda, disparadores[disp_id].carga_disparo);
    }
    
    if(lado == 'd' || lado == 'D'){
        if(pilha_vazia(disparadores[disp_id].direita)) return false;
        disparadores[disp_id].carga_disparo = desempilhar(&disparadores[disp_id].direita);
    } else if(lado == 'e' || lado == 'E'){
        if(pilha_vazia(disparadores[disp_id].esquerda)) return false;
        disparadores[disp_id].carga_disparo = desempilhar(&disparadores[disp_id].esquerda);
    } else {
        return false;
    }
    
    return true;
}

void* executar_disparo(int disp_id, double *novo_x, double *novo_y){
    if(disp_id < 0 || disp_id >= num_disparadores) return NULL;
    if(disparadores[disp_id].carga_disparo == NULL) return NULL;
    
    double angulo_rad = disparadores[disp_id].angulo * M_PI / 180.0;
    double velocidade = 100.0;
    
    *novo_x = disparadores[disp_id].x + cos(angulo_rad) * velocidade;
    *novo_y = disparadores[disp_id].y + sin(angulo_rad) * velocidade;
    
    void *forma_disparada = disparadores[disp_id].carga_disparo;
    disparadores[disp_id].carga_disparo = NULL;
    
    return forma_disparada;
}

void* clonar_forma(void *forma, char tipo){
    if(!forma) return NULL;
    
    if(tipo == 'c'){
        typedef struct { int id; double x, y, r; char corb[20], corp[20]; } CloneCirculo;
        CloneCirculo *orig = (CloneCirculo*)forma;
        CloneCirculo *clone = (CloneCirculo*)malloc(sizeof(CloneCirculo));
        if(clone) memcpy(clone, orig, sizeof(CloneCirculo));
        return clone;
    }
    else if(tipo == 'r'){
        typedef struct { int id; double x, y, w, h; char corb[20], corp[20]; } CloneRetangulo;
        CloneRetangulo *orig = (CloneRetangulo*)forma;
        CloneRetangulo *clone = (CloneRetangulo*)malloc(sizeof(CloneRetangulo));
        if(clone) memcpy(clone, orig, sizeof(CloneRetangulo));
        return clone;
    }
    
    return NULL;
}

void liberar_disparadores(){
    for(int i = 0; i < num_disparadores; i++){
        liberar_pilha(&disparadores[i].esquerda);
        liberar_pilha(&disparadores[i].direita);
        if(disparadores[i].carga_disparo){
            free(disparadores[i].carga_disparo);
        }
    }
    num_disparadores = 0;
}
