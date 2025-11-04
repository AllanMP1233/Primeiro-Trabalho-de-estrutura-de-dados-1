#ifndef CRIARTXT_H
#define CRIARTXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
criartxt cria arquivos de textos
*/

void criartxt(int id, double x, double y, char *conteudo, char *cor);
/*
    @brief Cria um arquivo de texto com as informações especificadas
    @param id Identificador do texto
    @param x Coordenada x do texto
    @param y Coordenada y do texto
    @param conteudo Conteúdo do texto
    @param cor Cor do texto
*/

#endif
/*
    @brief: Finaliza o módulo de criartxt.
*/
