#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "fila.h"
#include "pilha.h"
#include "criarsvg.h"
#include "arena.h"
#include "disparador.h"
#include "movimento.h"
#include "chao.h"
#include "colisao.h"
#include "qry.h"
#include "criartxt.h"

typedef struct { int id; double x, y, r; char cb[20], cp[20]; } CirculoI;
typedef struct { int id; double x, y, w, h; char cb[20], cp[20]; } RectI;

typedef struct {
    void *ptr;
    char tipo;
    int id;
} DBForma;

DBForma db[2000];
int db_qtd = 0;

void salvar_forma(void *p, char t, int id){
    if(db_qtd < 2000){
        db[db_qtd].ptr = p;
        db[db_qtd].tipo = t;
        db[db_qtd].id = id;
        db_qtd++;
    }
}

void* get_forma(int id, char *t_out){
    for(int i=0; i<db_qtd; i++){
        if(db[i].id == id){
            *t_out = db[i].tipo;
            return db[i].ptr;
        }
    }
    return NULL;
}

bool colisao_check(void *A, char tA, void *B, char tB){
    double xA, yA, rA=0, wA=0, hA=0;
    if(tA=='c'){ CirculoI *c=(CirculoI*)A; xA=c->x; yA=c->y; rA=c->r; }
    else if(tA=='r'){ RectI *r=(RectI*)A; xA=r->x; yA=r->y; wA=r->w; hA=r->h; }
    else return false;

    double xB, yB, rB=0, wB=0, hB=0;
    if(tB=='c'){ CirculoI *c=(CirculoI*)B; xB=c->x; yB=c->y; rB=c->r; }
    else if(tB=='r'){ RectI *r=(RectI*)B; xB=r->x; yB=r->y; wB=r->w; hB=r->h; }
    else return false;

    if(tA=='c' && tB=='c') return verificar_colisao_circulos(xA,yA,rA,xB,yB,rB);
    if(tA=='r' && tB=='r') return verificar_colisao_retangulos(xA,yA,wA,hA,xB,yB,wB,hB);
    if(tA=='c' && tB=='r') return verificar_colisao_circulo_retangulo(xA,yA,rA,xB,yB,wB,hB);
    if(tA=='r' && tB=='c') return verificar_colisao_circulo_retangulo(xB,yB,rB,xA,yA,wA,hA);
    return false;
}

int main(int argc, char *argv[]){
    char *e=".", *f=NULL, *o=".", *q=NULL;
    for(int i=1; i<argc; i++){
        if(!strcmp(argv[i],"-e")) e=argv[++i];
        else if(!strcmp(argv[i],"-f")) f=argv[++i];
        else if(!strcmp(argv[i],"-o")) o=argv[++i];
        else if(!strcmp(argv[i],"-q")) q=argv[++i];
    }
    if(!f) return 1;

    char pgeo[512], psvg[512], ptxt[512];
    sprintf(pgeo, "%s/%s", e, f);
    char base[256]; strcpy(base, f);
    char *dot = strrchr(base, '.'); if(dot) *dot='\0';
    sprintf(psvg, "%s/%s.svg", o, base);
    sprintf(ptxt, "%s/%s.txt", o, base);

    FILE *ft = fopen(ptxt, "w");
    if(!ft) return 1;
    
    fprintf(ft, "=== RELATORIO ===\nGEO: %s\n", f);

    iniciasvg(psvg, 800, 600);
    ARENA *arena = criar_arena(800,600);
    Fila *chao = criar_fila(1000);

    FILE *fg = fopen(pgeo, "r");
    if(!fg) { fclose(ft); return 1; }
    
    char l[512];
    while(fgets(l, sizeof(l), fg)){
        char cmd[10]; 
        if(sscanf(l, "%s", cmd) != 1) continue;

        if(!strcmp(cmd,"c")){
            int id; double x,y,r; char cb[20],cp[20];
            sscanf(l,"c %d %lf %lf %lf %s %s",&id,&x,&y,&r,cb,cp);
            Circulo *c=criarcirculo(id,x,y,r,cb,cp);
            enfileirar(chao,c); salvar_forma(c,'c',id);
            FILE *sv=fopen(psvg,"a"); desenharcirculo(c,sv); fclose(sv);
            fprintf(ft, "Circulo ID %d criado.\n", id);
        }
        else if(!strcmp(cmd,"r")){
            int id; double x,y,w,h; char cb[20],cp[20];
            sscanf(l,"r %d %lf %lf %lf %lf %s %s",&id,&x,&y,&w,&h,cb,cp);
            Rectan r=criarRetangulo(id,x,y,w,h,cb,cp);
            enfileirar(chao,r); salvar_forma(r,'r',id);
            FILE *sv=fopen(psvg,"a"); desenhar_ret(r,sv); fclose(sv);
            fprintf(ft, "Retangulo ID %d criado.\n", id);
        }
        else if(!strcmp(cmd,"l")){
             int id; double x1,y1,x2,y2; char cor[20];
             sscanf(l,"l %d %lf %lf %lf %lf %s",&id,&x1,&y1,&x2,&y2,cor);
             Linha *ln=criarlinha(id,x1,y1,x2,y2,cor);
             enfileirar(chao,ln);
        }
        else if(!strcmp(cmd,"t")){
            int id; double x,y; char cb[20],cp[20],anc,txt[200];
            sscanf(l,"t %d %lf %lf %s %s %c %[^\n]",&id,&x,&y,cb,cp,&anc,txt);
            Texto *tt=criartxt(id,x,y,txt,cb);
            enfileirar(chao,tt);
            gerartxt(ptxt,id,x,y,txt,cb);
        }
        else if(!strcmp(cmd,"pd")){
            int id; double x,y,rot;
            sscanf(l,"pd %d %lf %lf %lf",&id,&x,&y,&rot);
            adicionar_disparador(id,x,y,rot);
            desenhar_disparador_svg(psvg,x,y,rot,id);
            fprintf(ft, "Disparador ID %d criado.\n", id);
        }
    }
    fclose(fg);

    if(q){
        char pqry[512]; sprintf(pqry, "%s/%s", e, q);
        FILE *fq = fopen(pqry, "r");
        
        criararquivoqry(psvg, q);
        fprintf(ft, "\n--- QRY: %s ---\n", q);

        if(fq){
            while(fgets(l, sizeof(l), fq)){
                char cmd[10]; 
                if(sscanf(l, "%s", cmd) != 1) continue;
                
                if(!strcmp(cmd,"lc")){
                    int idD, idF; char lado;
                    sscanf(l, "lc %d %c %d", &idD, &lado, &idF);
                    int idx = buscar_disparador_por_id(idD);
                    if(idx == -1) { fprintf(ft,"ERRO LC: Disp %d nao existe.\n", idD); continue; }
                    
                    char tf; void *orig = get_forma(idF, &tf);
                    if(!orig) { fprintf(ft,"ERRO LC: Forma %d nao existe.\n", idF); continue; }
                    
                    void *clone = clonar_forma(orig, tf);
                    if(carregar_forma(idx, lado, clone, tf)){
                        fprintf(ft,"LC: Disp %d carregou Forma %d.\n", idD, idF);
                    }
                }
                else if(!strcmp(cmd,"dsp")){
                    int idD; sscanf(l,"dsp %d", &idD);
                    int idx = buscar_disparador_por_id(idD);
                    if(idx == -1) { fprintf(ft,"ERRO DSP: Disp %d nao existe.\n", idD); continue; }
                    
                    double dx, dy, dang; int rid;
                    obter_dados_disparador(idx, &dx, &dy, &dang, &rid);

                    double nx, ny;
                    void *proj = executar_disparo(idx, &nx, &ny);
                    
                    if(proj){
                        FILE *sv = fopen(psvg,"a");
                        fprintf(sv,"<line x1=\"%.2f\" y1=\"%.2f\" x2=\"%.2f\" y2=\"%.2f\" stroke=\"red\" stroke-dasharray=\"5\" stroke-width=\"2\"/>\n", dx+10, dy+10, nx, ny);
                        fprintf(sv,"<circle cx=\"%.2f\" cy=\"%.2f\" r=\"3\" fill=\"orange\" stroke=\"black\"/>\n", nx, ny);
                        fclose(sv);

                        mover_forma_na_arena(proj, 'c', nx, ny, arena);
                        fprintf(ft,"DSP: Disp %d disparou. Alvo: (%.2f, %.2f).\n", idD, nx, ny);
                        
                        bool colidiu = false;
                        for(int k=0; k<db_qtd; k++){
                            if(colisao_check(proj, 'c', db[k].ptr, db[k].tipo)){
                                fprintf(ft," -> COLISAO: Atingiu Forma ID %d\n", db[k].id);
                                FILE *s = fopen(psvg,"a");
                                fprintf(s,"<text x=\"%.2f\" y=\"%.2f\" fill=\"red\" font-weight=\"bold\" font-size=\"20\">X</text>\n", nx, ny);
                                fclose(s);
                                colidiu = true;
                            }
                        }
                        if(!colidiu) fprintf(ft," -> Sem colisao.\n");
                        free(proj);
                    } else {
                        fprintf(ft,"FALHA DSP: Disp %d sem municao.\n", idD);
                    }
                }
            }
            fclose(fq); 
        } else {
            fprintf(ft, "ERRO: Nao foi possivel abrir o arquivo QRY.\n");
        }
    }
    
    finalizarsvg(psvg);
    if(ft) fclose(ft);

    liberar_arena(arena);
    liberar_disparadores();
    liberar_fila(chao);
    return 0;
}