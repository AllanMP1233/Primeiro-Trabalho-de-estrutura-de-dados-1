#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arena.h"

struct arena{
    int largura;
    int comprimento;
    char **mapa;
};

ARENA* criar_arena(int largura, int comprimento){
    ARENA *a = (ARENA*) malloc(sizeof(ARENA));
    if (a == NULL) {
        printf("Erro ao alocar memória para a arena.\n");
        exit(1);
    }
    a->largura = largura;
    a->comprimento = comprimento;

    a->mapa = (char**) malloc(comprimento * sizeof(char*));
    for(int i = 0; i < comprimento; i++){
        a->mapa[i] = (char*) malloc(largura * sizeof(char));
        memset(a->mapa[i], '_', largura);
    }
    return a;
}

void liberar_arena(ARENA *a){
    for(int i = 0; i < a->comprimento; i++){
        free(a->mapa[i]);
    }
    free(a->mapa);
    free(a);
}

void imprimir_arena(ARENA *a){
    for(int i = 0; i < a->comprimento; i++){
        for(int j = 0; j < a->largura; j++){
            printf("%c ", a->mapa[i][j]);
        }
        printf("\n");
    }
}
