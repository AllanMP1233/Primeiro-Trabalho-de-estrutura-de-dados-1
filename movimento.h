#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arena.h" 

void mover_forma_na_arena(void *forma, char tipo_forma, double novo_x, double novo_y, ARENA *arena);
/*
    @brief Move uma forma geometrica para x,y.
*/

#endif