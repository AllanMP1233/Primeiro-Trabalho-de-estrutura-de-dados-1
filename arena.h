#ifndef ARENA_H
#define ARENA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
Arena é um espaço cujo mapa representa o local onde ocorrem as batalhas entre as formas geométricas.
Ela possui largura e comprimento, além de um mapa representado por uma matriz de caracteres.
*/

typedef struct arena ARENA;

ARENA* criar_arena(int largura, int comprimento);
/*
    @brief: Cria uma nova arena com as dimensões especificadas.
    @param largura: Largura da arena.
    @param comprimento: Comprimento da arena.
    @return: Ponteiro para a arena criada.
*/

void liberar_arena(ARENA *a);
/*
    @brief: Libera a memória alocada para a arena.
    @param a: Ponteiro para a arena a ser liberada.
*/

void imprimir_arena(ARENA *a);
/*
    @brief: Imprime o mapa da arena no console.
    @param a: Ponteiro para a arena a ser impressa.
*/

#endif
/*
    @brief: Finaliza o módulo de arena.
*/
