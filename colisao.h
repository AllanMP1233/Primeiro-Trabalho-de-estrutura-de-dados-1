#ifndef COLISAO_H
#define COLISAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Colisão é o módulo responsável por detectar e calcular sobreposições entre formas geométricas.
Ele fornece funções para verificar colisões entre círculos, retângulos e suas combinações,
além de calcular as áreas de interseção para o cálculo de pontuação do jogo.
*/

void cirarcolisao(char *nomearqsvg, char *nomearqcolisao);
/*
    @brief: Cria um arquivo de colisão com o nome especificado
    @param nomearqsvg: Nome do arquivo SVG de saída
    @param nomearqcolisao: Nome do arquivo de colisão de entrada
*/

void mover_forma_na_arena(void *forma, char tipo_forma, double novo_x, double novo_y, void *arena);
/*
    @brief: Move uma forma geométrica para uma nova posição na arena
    @param forma: Ponteiro para a forma geométrica a ser movida
    @param tipo_forma: Tipo da forma ('c' para círculo, 'r' para retângulo, 'l' para linha, 't' para texto)
    @param novo_x: Nova coordenada x para a forma
    @param novo_y: Nova coordenada y para a forma
    @param arena: Ponteiro para a arena onde a forma está localizada (pode ser NULL)
*/

bool verificar_colisao_circulos(double x1, double y1, double r1, double x2, double y2, double r2);
/*
    @brief: Verifica se dois círculos estão colidindo
    @param x1: Coordenada x do centro do primeiro círculo
    @param y1: Coordenada y do centro do primeiro círculo
    @param r1: Raio do primeiro círculo
    @param x2: Coordenada x do centro do segundo círculo
    @param y2: Coordenada y do centro do segundo círculo
    @param r2: Raio do segundo círculo
    @return: true se há colisão, false caso contrário
*/

bool verificar_colisao_retangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2);
/*
    @brief: Verifica se dois retângulos estão colidindo
    @param x1: Coordenada x do canto inferior esquerdo do primeiro retângulo
    @param y1: Coordenada y do canto inferior esquerdo do primeiro retângulo
    @param w1: Largura do primeiro retângulo
    @param h1: Altura do primeiro retângulo
    @param x2: Coordenada x do canto inferior esquerdo do segundo retângulo
    @param y2: Coordenada y do canto inferior esquerdo do segundo retângulo
    @param w2: Largura do segundo retângulo
    @param h2: Altura do segundo retângulo
    @return: true se há colisão, false caso contrário
*/

bool verificar_colisao_circulo_retangulo(double cx, double cy, double r, double rx, double ry, double w, double h);
/*
    @brief: Verifica se um círculo e um retângulo estão colidindo
    @param cx: Coordenada x do centro do círculo
    @param cy: Coordenada y do centro do círculo
    @param r: Raio do círculo
    @param rx: Coordenada x do canto inferior esquerdo do retângulo
    @param ry: Coordenada y do canto inferior esquerdo do retângulo
    @param w: Largura do retângulo
    @param h: Altura do retângulo
    @return: true se há colisão, false caso contrário
*/

double calcular_area_intersecao_circulos(double x1, double y1, double r1, double x2, double y2, double r2);
/*
    @brief: Calcula a área de interseção entre dois círculos
    @param x1: Coordenada x do centro do primeiro círculo
    @param y1: Coordenada y do centro do primeiro círculo
    @param r1: Raio do primeiro círculo
    @param x2: Coordenada x do centro do segundo círculo
    @param y2: Coordenada y do centro do segundo círculo
    @param r2: Raio do segundo círculo
    @return: Área de interseção em unidades quadradas
*/

double calcular_area_intersecao_retangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2);
/*
    @brief: Calcula a área de interseção entre dois retângulos
    @param x1: Coordenada x do canto inferior esquerdo do primeiro retângulo
    @param y1: Coordenada y do canto inferior esquerdo do primeiro retângulo
    @param w1: Largura do primeiro retângulo
    @param h1: Altura do primeiro retângulo
    @param x2: Coordenada x do canto inferior esquerdo do segundo retângulo
    @param y2: Coordenada y do canto inferior esquerdo do segundo retângulo
    @param w2: Largura do segundo retângulo
    @param h2: Altura do segundo retângulo
    @return: Área de interseção em unidades quadradas
*/

#endif
/*
    @brief: Finaliza o módulo de colisão
*/
