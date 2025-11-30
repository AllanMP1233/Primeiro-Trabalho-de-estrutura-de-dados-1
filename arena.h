#ifndef ARENA_H
#define ARENA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arena ARENA;

ARENA* criar_arena(int largura, int comprimento);
/*
    Aloca e inicializa uma nova arena com as dimensões especificadas.
    Retorna o ponteiro opaco para a estrutura.
*/

void liberar_arena(ARENA *a);
/*
    Libera a memória da estrutura da arena e de sua matriz interna.
*/

void imprimir_arena(ARENA *a);
/*
    Função auxiliar para imprimir o estado da arena no console (debug).
*/

#endif