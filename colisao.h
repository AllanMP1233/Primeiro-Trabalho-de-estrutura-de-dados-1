#ifndef COLISAO_H
#define COLISAO_H

#include <stdbool.h>

void cirarcolisao(char *nomearqsvg, char *nomearqcolisao);
/*
    @brief Inicializa arquivo de colisao.
*/

bool verificar_colisao_circulos(double x1, double y1, double r1, double x2, double y2, double r2);
/*
    @brief Verifica colisao entre dois circulos.
*/

bool verificar_colisao_retangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2);
/*
    @brief Verifica colisao entre dois retangulos.
*/

bool verificar_colisao_circulo_retangulo(double cx, double cy, double cr, double rx, double ry, double rw, double rh);
/*
    @brief Verifica colisao entre circulo e retangulo.
*/

double calcular_area_intersecao_circulos(double x1, double y1, double r1, double x2, double y2, double r2);
/*
    @brief Calcula area intersecao de circulos.
*/

double calcular_area_intersecao_retangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2);
/*
    @brief Calcula area intersecao de retangulos.
*/

#endif