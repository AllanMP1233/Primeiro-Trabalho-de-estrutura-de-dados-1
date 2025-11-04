#ifndef CRIARSVG_H
#define CRIARSVG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void iniciasvg(char *nomearqsvg, double largura, double altura);
/*
    @brief Inicia um arquivo SVG com as dimensões especificadas
    @param nomearqsvg Nome do arquivo SVG de saída
    @param largura Largura do SVG
    @param altura Altura do SVG
*/

void finalizarsvg(char *nomearqsvg);
/*
    @brief Finaliza um arquivo SVG
    @param nomearqsvg Nome do arquivo SVG de saída
*/

#endif
/*
    @brief: Finaliza o módulo de criarsvg.
*/
