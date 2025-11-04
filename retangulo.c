#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "retangulo.h"

struct retangulo{
    int id;
    double x;
    double y;
    double l;
    double h;
    char corb[20];
    char corp[20];
};

Rectan criarRetangulo(int id, double x, double y, double l, double h, char *corb, char *corp){
    struct retangulo *r = (struct retangulo*)malloc(sizeof(struct retangulo));
    if (r == NULL) {
        printf("Erro ao alocar memória para o retangulo.\n");
        exit(1);
    }
    r->id = id;
    r->x = x;
    r->y = y;
    r->l = l;
    r->h = h;
    strcpy(r->corb, corb);
    strcpy(r->corp, corp);
    return r;
}

int obter_id_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return retangulo->id;
}

double obter_x_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return retangulo->x;
}

double obter_y_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return retangulo->y;
}

double obter_l_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return retangulo->l;
}

double obter_h_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return retangulo->h;
}

char* obter_corb_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return retangulo->corb;
}

char* obter_corp_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return retangulo->corp;
}

double obter_area_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return retangulo->l * retangulo->h;
}

double obter_perimetro_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    return 2 * (retangulo->l + retangulo->h);
}

void desenhar_ret(Rectan r, FILE* arq){
    struct retangulo *retangulo = (struct retangulo *)r;
    fprintf(arq, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\" />\n", 
            retangulo->x, retangulo->y, retangulo->l, retangulo->h, retangulo->corb, retangulo->corp);
}

void liberar_ret(Rectan r){
    struct retangulo *retangulo = (struct retangulo *)r;
    free(retangulo);
}
