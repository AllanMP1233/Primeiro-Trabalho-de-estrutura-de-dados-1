#ifndef fila_h
#define fila_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct fila Fila;

Fila* criar_fila(int capacidade);
/*
    @brief Cria uma fila com a capacidade especificada
    @param capacidade Capacidade máxima da fila
    @return Retorna um ponteiro para a fila criada
*/

bool fila_vazia(Fila *f);
/*
    @brief Verifica se a fila está vazia
    @param f Ponteiro para a fila
    @return Retorna true se a fila estiver vazia, false caso contrário
*/

bool fila_cheia(Fila *f);
/*
    @brief Verifica se a fila está cheia
    @param f Ponteiro para a fila
    @return Retorna true se a fila estiver cheia, false caso contrário
*/

void enfileirar(Fila *f, void *elemento);
/*
    @brief Adiciona um elemento ao final da fila
    @param f Ponteiro para a fila
    @param elemento Ponteiro para o elemento a ser adicionado
*/

void* desenfileirar(Fila *f);
/*
    @brief Remove e retorna o elemento do início da fila
    @param f Ponteiro para a fila
    @return Retorna um ponteiro para o elemento removido, ou NULL se a fila estiver vazia
*/

void liberar_fila(Fila *f);
/*
    @brief Libera a memória alocada para a fila
    @param f Ponteiro para a fila
*/

#endif
/*
    @brief: Finaliza o módulo de fila.
*/
