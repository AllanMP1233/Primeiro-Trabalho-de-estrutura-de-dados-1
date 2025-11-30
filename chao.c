#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chao.h"

// DEFINIÇÃO COMPLETA DA ESTRUTURA
struct solo{
    int largura;
    int comprimento;
    char **mapa;
};

// Ajuste para retornar SOLO* (que é struct solo*)
SOLO* criar_solo(int largura, int comprimento){
    // Aloca a struct completa
    SOLO *s = (SOLO*) malloc(sizeof(struct solo)); 
    if (s == NULL) {
        printf("Erro ao alocar memória para o solo.\n");
        exit(1);
    }

    s->largura = largura;
    s->comprimento = comprimento;
    // Alocação do mapa (linhas)
    s->mapa = (char**) malloc(comprimento * sizeof(char*));
    if (s->mapa == NULL) {
        printf("Erro ao alocar memória para o mapa do solo.\n");
        free(s);
        exit(1);
    }

    for(int i = 0; i < comprimento; i++){
        // Alocação de cada linha (colunas)
        s->mapa[i] = (char*) malloc(largura * sizeof(char));
        if (s->mapa[i] == NULL) {
            printf("Erro ao alocar memória para a linha do solo.\n");
            for (int j = 0; j < i; j++) {
                free(s->mapa[j]);
            }
            free(s->mapa);
            free(s);
            exit(1);
        }
        memset(s->mapa[i], '_', largura);
    }

    return s;
}

// Ajuste para receber SOLO *s
void liberar_solo(SOLO *s){
    if (!s) return;
    for(int i = 0; i < s->comprimento; i++){
        free(s->mapa[i]);
    }
    free(s->mapa);
    free(s);
}

// Ajuste para receber SOLO *s
void imprimir_solo(SOLO *s){
    if (!s) return;
    for(int i = 0; i < s->comprimento; i++){
        for(int j = 0; j < s->largura; j++){
            printf("%c ", s->mapa[i][j]);
        }
        printf("\n");
    }
}