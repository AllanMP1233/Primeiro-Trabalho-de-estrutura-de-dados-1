#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct pilha{
    void *elemento;
    struct pilha *proximo;
};

Pilha* criar_pilha(){
    return NULL;
}

bool pilha_vazia(Pilha *p){
    return p == NULL;
}

void empilhar(Pilha **p, void *elemento){
    Pilha *novo_no = (Pilha *)malloc(sizeof(Pilha));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória para o novo nó da pilha.\n");
        exit(1);
    }
    novo_no->elemento = elemento;
    novo_no->proximo = *p;
    *p = novo_no;
}

void* desempilhar(Pilha **p){
    if (pilha_vazia(*p)) {
        return NULL;
    }
    Pilha *topo = *p;
    void *elemento = topo->elemento;
    *p = topo->proximo;
    free(topo);
    return elemento;
}

void liberar_pilha(Pilha **p){
    while (!pilha_vazia(*p)) {
        desempilhar(p);
    }
}
