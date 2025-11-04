#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fila.h"

struct fila{
    void **elementos;
    int capacidade;
    int tamanho;
    int inicio;
    int fim;
};

Fila* criar_fila(int capacidade){
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    f->capacidade = capacidade;
    f->tamanho = 0;
    f->inicio = 0;
    f->fim = -1;
    f->elementos = (void **)malloc(capacidade * sizeof(void *));
    if (f->elementos == NULL) {
        printf("Erro ao alocar memória para os elementos da fila.\n");
        free(f);
        exit(1);
    }
    return f;
}

bool fila_vazia(Fila *f){
    return f->tamanho == 0;
}

bool fila_cheia(Fila *f){
    return f->tamanho == f->capacidade;
}

void enfileirar(Fila *f, void *elemento){
    if (fila_cheia(f)) {
        printf("Fila cheia. Não é possível enfileirar.\n");
        return;
    }
    f->fim = (f->fim + 1) % f->capacidade;
    f->elementos[f->fim] = elemento;
    f->tamanho++;
}

void* desenfileirar(Fila *f){
    if (fila_vazia(f)) {
        printf("Fila vazia. Não é possível desenfileirar.\n");
        return NULL;
    }
    void *elemento = f->elementos[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    return elemento;
}

void liberar_fila(Fila *f){
    free(f->elementos);
    free(f);
}
