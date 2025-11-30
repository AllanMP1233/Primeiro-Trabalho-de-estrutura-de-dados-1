#ifndef CRIARTXT_H
#define CRIARTXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gerartxt(char *nomearqtxt, int id, double x, double y, char *conteudo, char *cor);
/*
    @brief Escreve os dados de um elemento de texto no relatório TXT.
    @param nomearqtxt Nome do ficheiro de saída.
    @param id ID do texto.
    @param x Coordenada X.
    @param y Coordenada Y.
    @param conteudo O texto propriamente dito.
    @param cor A cor do texto.
*/

#endif