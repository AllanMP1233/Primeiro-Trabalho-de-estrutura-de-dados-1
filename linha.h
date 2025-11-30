#ifndef linha_h
#define linha_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Uma linha é uma forma geométrica definida por dois pontos (x1,y1) e (x2,y2).
A linha é representada por dois pontos (x1,y1) e (x2,y2), além disso a linha possui uma cor.
A sua cor é representada por cor.
*/

typedef struct linha Linha;

Linha* criarlinha(int id, double x1, double y1, double x2, double y2, char *cor);
/*
    @brief Cria uma linha com os parâmetros passados
    @param id Identificador da linha
    @param x1 Coordenada x do primeiro ponto
    @param y1 Coordenada y do primeiro ponto
    @param x2 Coordenada x do segundo ponto
    @param y2 Coordenada y do segundo ponto
    @param cor Cor da linha
    @return Retorna um ponteiro para a linha criada
*/

int obteridlinha(Linha *l);
/*
    @brief Obtém o id da linha
    @param l Ponteiro para a linha
    @return Retorna o id da linha
*/

double obterx1linha(Linha *l);
/*
    @brief Obtém a coordenada x do primeiro ponto da linha
    @param l Ponteiro para a linha
    @return Retorna a coordenada x do primeiro ponto da linha
*/

double obtery1linha(Linha *l);
/*
    @brief Obtém a coordenada y do primeiro ponto da linha
    @param l Ponteiro para a linha
    @return Retorna a coordenada y do primeiro ponto da linha
*/

double obterx2linha(Linha *l);
/*
    @brief Obtém a coordenada x do segundo ponto da linha
    @param l Ponteiro para a linha
    @return Retorna a coordenada x do segundo ponto da linha
*/

double obery2linha(Linha *l);
/*
    @brief Obtém a coordenada y do segundo ponto da linha
    @param l Ponteiro para a linha
    @return Retorna a coordenada y do segundo ponto da linha
*/

char* obtercorlinha(Linha *l);
/*
    @brief Obtém a cor da linha
    @param l Ponteiro para a linha
    @return Retorna a cor da linha
*/

void liberarlinha(Linha *l);
/*
    @brief Libera a memória alocada para a linha
    @param l Ponteiro para a linha
*/

#endif
// Removido o /* que estava fechando o módulo.