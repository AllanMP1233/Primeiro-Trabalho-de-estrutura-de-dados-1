#ifndef CHAO_H
#define CHAO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct solo SOLO;

SOLO* criar_solo(int largura, int comprimento);
/*
    Aloca e inicializa a estrutura do solo (chão) onde as formas repousam.
    Retorna o ponteiro opaco.
*/

void liberar_solo(SOLO *s);
/*
    Libera toda a memória alocada para o solo.
*/

void imprimir_solo(SOLO *s);
/*
    Imprime o estado do solo no console para verificação.
*/

#endif