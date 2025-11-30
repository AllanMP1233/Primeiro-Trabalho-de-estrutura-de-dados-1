#include "linha.h" // Corrigido de "lina.h" para "linha.h"
#include <stdio.h>
#include <stdlib.h> // Corrigido de "stdlib.h" para <stdlib.h>
#include <string.h> // Corrigido de "string.h" para <string.h>
#include <stdbool.h> // Corrigido de "stdbool.h"4 para <stdbool.h>

struct linha{
    int id;
    double x1;
    double y1;
    double x2;
    double y2;
    char cor[20];
}; // Removida a variável global 'Linha' após o ponto e vírgula

Linha* criarlinha(int id, double x1, double y1, double x2, double y2, char *cor){
    // O tipo de ponteiro é Linha* e o tamanho alocado é sizeof(struct linha) ou sizeof(*l)
    Linha *l = (Linha *)malloc(sizeof(struct linha)); 
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
    if (!l) return -1; // Adicionando checagem básica
    return l->id;
}

double obterx1linha(Linha *l){
    if (!l) return 0.0;
    return l->x1;
}

double obery1linha(Linha *l){
    if (!l) return 0.0;
    return l->y1;
}

double obterx2linha(Linha *l){
    if (!l) return 0.0;
    return l->x2;
}

double obery2linha(Linha *l){
    if (!l) return 0.0;
    return l->y2;
}

char* obtercorlinha(Linha *l){
    if (!l) return NULL;
    return l->cor;
}

void liberarlinha(Linha *l){
    free(l);
}