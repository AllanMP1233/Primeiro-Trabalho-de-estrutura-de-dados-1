#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pilha Pilha;

Pilha* criar_pilha();
/*
    @brief Cria uma pilha vazia
    @return Retorna um ponteiro para a pilha criada
*/

bool pilha_vazia(Pilha *p);
/*
    @brief Verifica se a pilha está vazia
    @param p Ponteiro para a pilha
    @return Retorna true se a pilha estiver vazia, false caso contrário
*/

void empilhar(Pilha **p, void *elemento);
/*
    @brief Adiciona um elemento no topo da pilha
    @param p Ponteiro para a pilha
    @param elemento Ponteiro para o elemento a ser adicionado
*/

void* desempilhar(Pilha **p);
/*
    @brief Remove e retorna o elemento do topo da pilha
    @param p Ponteiro para a pilha
    @return Retorna um ponteiro para o elemento removido, ou NULL se a pilha estiver vazia
*/

void liberar_pilha(Pilha **p);
/*
    @brief Libera a memória alocada para a pilha
    @param p Ponteiro para a pilha
*/

#endif
/*
    @brief: Finaliza o módulo de pilha.
*/
