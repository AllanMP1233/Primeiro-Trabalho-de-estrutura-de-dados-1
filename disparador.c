#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "disparador.h"
#include "pilha.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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

void desenhar_disparador_svg(char *nomearqsvg, double x, double y, double angulo, int id){
    FILE *saida = fopen(nomearqsvg, "a");
    if (saida == NULL) return;
    
    fprintf(saida, "<rect x=\"%.2f\" y=\"%.2f\" width=\"20\" height=\"20\" fill=\"green\" stroke=\"black\" stroke-width=\"1\" />\n", x, y);
    
    double rad = angulo * M_PI / 180.0;
    double cx = x + 10;
    double cy = y + 10;
    double fx = cx + 25 * cos(rad);
    double fy = cy + 25 * sin(rad);
    
    fprintf(saida, "<line x1=\"%.2f\" y1=\"%.2f\" x2=\"%.2f\" y2=\"%.2f\" stroke=\"black\" stroke-width=\"3\" />\n", cx, cy, fx, fy);
    fprintf(saida, "<text x=\"%.2f\" y=\"%.2f\" fill=\"white\" font-size=\"8\">%d</text>\n", x+2, y+15, id);
    
    fclose(saida);
}

int adicionar_disparador(int id, double x, double y, double angulo){
    if(num_disparadores >= 100) return -1;
    int i = num_disparadores;
    disparadores[i].id = id;
    disparadores[i].x = x;
    disparadores[i].y = y;
    disparadores[i].angulo = angulo;
    disparadores[i].esquerda = criar_pilha();
    disparadores[i].direita = criar_pilha();
    disparadores[i].carga_disparo = NULL;
    disparadores[i].tipo_disparo = '\0';
    num_disparadores++;
    return i;
}

int buscar_disparador_por_id(int id_real){
    for(int i=0; i<num_disparadores; i++){
        if(disparadores[i].id == id_real) return i;
    }
    return -1;
}

bool obter_dados_disparador(int indice, double *x, double *y, double *ang, int *id_real){
    if(indice < 0 || indice >= num_disparadores) return false;
    *x = disparadores[indice].x;
    *y = disparadores[indice].y;
    *ang = disparadores[indice].angulo;
    *id_real = disparadores[indice].id;
    return true;
}

bool carregar_forma(int indice, char lado, void *forma, char tipo){
    if(indice < 0 || indice >= num_disparadores || !forma) return false;
    if(lado == 'd' || lado == 'D'){
        empilhar(&disparadores[indice].direita, forma);
    } else if(lado == 'e' || lado == 'E'){
        empilhar(&disparadores[indice].esquerda, forma);
    } else {
        return false;
    }
    disparadores[indice].tipo_disparo = tipo;
    return true;
}

bool selecionar_carga(int indice, char lado){
    if(indice < 0 || indice >= num_disparadores) return false;
    if(disparadores[indice].carga_disparo != NULL){
        empilhar(&disparadores[indice].esquerda, disparadores[indice].carga_disparo);
        disparadores[indice].carga_disparo = NULL;
    }
    if(lado == 'd' || lado == 'D'){
        if(pilha_vazia(disparadores[indice].direita)) return false;
        disparadores[indice].carga_disparo = desempilhar(&disparadores[indice].direita);
    } else if(lado == 'e' || lado == 'E'){
        if(pilha_vazia(disparadores[indice].esquerda)) return false;
        disparadores[indice].carga_disparo = desempilhar(&disparadores[indice].esquerda);
    } else {
        return false;
    }
    return true;
}

void* executar_disparo(int indice, double *novo_x, double *novo_y){
    if(indice < 0 || indice >= num_disparadores) return NULL;
    if(disparadores[indice].carga_disparo == NULL) return NULL;
    
    double angulo_rad = disparadores[indice].angulo * M_PI / 180.0;
    double velocidade = 100.0; 
    
    double cx = disparadores[indice].x + 10;
    double cy = disparadores[indice].y + 10;
    
    *novo_x = cx + cos(angulo_rad) * velocidade;
    *novo_y = cy + sin(angulo_rad) * velocidade;
    
    void *forma = disparadores[indice].carga_disparo;
    disparadores[indice].carga_disparo = NULL;
    return forma;
}

void* clonar_forma(void *forma, char tipo){
    if(!forma) return NULL;
    if(tipo == 'c'){
        typedef struct { int id; double x, y, r; char cb[20], cp[20]; } CloneCirculo;
        CloneCirculo *orig = (CloneCirculo*)forma;
        CloneCirculo *clone = (CloneCirculo*)malloc(sizeof(CloneCirculo));
        if(clone) memcpy(clone, orig, sizeof(CloneCirculo));
        return clone;
    } else if(tipo == 'r'){
        typedef struct { int id; double x, y, w, h; char cb[20], cp[20]; } CloneRetangulo;
        CloneRetangulo *orig = (CloneRetangulo*)forma;
        CloneRetangulo *clone = (CloneRetangulo*)malloc(sizeof(CloneRetangulo));
        if(clone) memcpy(clone, orig, sizeof(CloneRetangulo));
        return clone;
    }
    return NULL;
}

void liberar_disparadores(void){
    for(int i = 0; i < num_disparadores; i++){
        if(disparadores[i].esquerda) liberar_pilha(&disparadores[i].esquerda);
        if(disparadores[i].direita) liberar_pilha(&disparadores[i].direita);
    }
    num_disparadores = 0;
}