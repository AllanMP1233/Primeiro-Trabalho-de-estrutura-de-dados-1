#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

struct texto {
    int id;
    double x;
    double y;
    char corb[24];
    char conteudo[255];
};

void* criartxt(int id, double x, double y, char *conteudo, char *corb){
    struct texto *t = (struct texto*)malloc(sizeof(struct texto));
    if(t){
        t->id = id;
        t->x = x;
        t->y = y;
        if(corb) strcpy(t->corb, corb);
        if(conteudo) strcpy(t->conteudo, conteudo);
    }
    return t;
}

double obter_x_txt(void *t){
    struct texto *texto = (struct texto*)t;
    return texto->x;
}

double obter_y_txt(void *t){
    struct texto *texto = (struct texto*)t;
    return texto->y;
}

char* obter_conteudo_txt(void *t){
    struct texto *texto = (struct texto*)t;
    return texto->conteudo;
}

void liberar_texto(void *t){
    if(t) free(t);
}