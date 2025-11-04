#ifndef CHAO_H
#define CHAO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Solo é a base onde a arena está localizada.
Ele possui largura e comprimento, além de um mapa representado por uma matriz de caracteres.
*/

typedef struct solo SOLO;

SOLO* criar_solo(int largura, int comprimento);
/*
    @brief: Cria um novo solo com as dimensões especificadas.
    @param largura: Largura do solo.
    @param comprimento: Comprimento do solo.
    @return: Ponteiro para o solo criado.
*/

void liberar_solo(SOLO *s);
/*
    @brief: Libera a memória alocada para o solo.
    @param s: Ponteiro para o solo a ser liberado.
*/

void imprimir_solo(SOLO *s);
/*
    @brief: Imprime o mapa do solo no console.
    @param s: Ponteiro para o solo a ser impresso.
*/

#endif
/*
    @brief: Finaliza o módulo de chão.
*/
