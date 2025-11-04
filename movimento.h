#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Movimento é o módulo responsável por gerenciar os movimentos das formas geométricas na arena.
Ele permite mover formas geométricas para novas posições dentro da arena, garantindo que os movimentos sejam válidos 
e não resultem em colisões com outras formas ou saídas dos limites da arena.
*/

void mover_forma_na_arena(void *forma, char tipo_forma, double novo_x, double novo_y, void *arena);
/*
    @brief: Move uma forma geométrica para uma nova posição na arena.
    @param forma: Ponteiro para a forma geométrica a ser movida.
    @param tipo_forma: Tipo da forma geométrica ('c' para círculo, 'r' para retângulo, 'l' para linha).
    @param novo_x: Nova coordenada x para a forma.
    @param novo_y: Nova coordenada y para a forma.
    @param arena: Ponteiro para a arena onde a forma está localizada.
*/

#endif
/*
    @brief: Finaliza o módulo de movimento.
*/
