#include "linha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct linha{
    int id;
    double x1;
    double y1;
    double x2;
    double y2;
    char cor[20];
};

Linha* criarlinha(int id, double x1, double y1, double x2, double y2, char *cor){
    Linha *l = (Linha *)malloc(sizeof(Linha));
    if (l == NULL) {
        printf("Erro ao alocar memória para a linha.\n");
        exit(1);
    }
    l->id = id;
    l->x1 = x1;
    l->y1 = y1;
    l->x2 = x2;
    l->y2 = y2;
    strcpy(l->cor, cor);
    return l;
}

int obteridlinha(Linha *l){
    return l->id;
}

double obterx1linha(Linha *l){
    return l->x1;
}

double obtery1linha(Linha *l){
    return l->y1;
}

double obterx2linha(Linha *l){
    return l->x2;
}

double obtery2linha(Linha *l){
    return l->y2;
}

char* obtercorlinha(Linha *l){
    return l->cor;
}

void liberarlinha(Linha *l){
    free(l);
}
