#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "chao.h"

struct solo{
    int largura;
    int comprimento;
    char **mapa;
};

SOLO* criar_solo(int largura, int comprimento){
    SOLO *s = (SOLO*) malloc(sizeof(SOLO));
    if (s == NULL) {
        printf("Erro ao alocar memória para o solo.\n");
        exit(1);
    }
    s->largura = largura;
    s->comprimento = comprimento;

    s->mapa = (char**) malloc(comprimento * sizeof(char*));
    for(int i = 0; i < comprimento; i++){
        s->mapa[i] = (char*) malloc(largura * sizeof(char));
        memset(s->mapa[i], '_', largura);
    }
    return s;
}

void liberar_solo(SOLO *s){
    for(int i = 0; i < s->comprimento; i++){
        free(s->mapa[i]);
    }
    free(s->mapa);
    free(s);
}

void imprimir_solo(SOLO *s){
    for(int i = 0; i < s->comprimento; i++){
        for(int j = 0; j < s->largura; j++){
            printf("%c ", s->mapa[i][j]);
        }
        printf("\n");
    }
}
