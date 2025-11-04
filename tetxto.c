#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "texto.h"

struct texto{
    int id;
    double x;
    double y;
    char conteudo[100];
    char cor[20];
};

Texto* criartxt(int id, double x, double y, char *conteudo, char *cor){
    Texto *t = (Texto *)malloc(sizeof(Texto));
    if (t == NULL) {
        printf("Erro ao alocar memória para o texto.\n");
        exit(1);
    }
    t->id = id;
    t->x = x;
    t->y = y;
    strcpy(t->conteudo, conteudo);
    strcpy(t->cor, cor);
    return t;
}

int obter_id_txt(Texto *t){
    return t->id;
}

double obter_x_txt(Texto *t){
    return t->x;
}

double obter_y_txt(Texto *t){
    return t->y;
}

char* obter_conteudo_txt(Texto *t){
    return t->conteudo;
}

char* obter_cor_txt(Texto *t){
    return t->cor;
}

void liberar_txt(Texto *t){
    free(t);
}

double calcular_area_txt(Texto *t){
    return 0.0;
}

double calcular_perimetro_txt(Texto *t){
    return 0.0;
}
