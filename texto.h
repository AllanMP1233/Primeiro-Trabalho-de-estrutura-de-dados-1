#ifndef TEXTO_H
#define TEXTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
Um texto é uma forma geométrica definida por sua posição (x,y) e seu conteúdo textual.
O texto é representado por um ponto (x,y) que é a posição do texto na tela,
e por seu conteúdo textual, além disso o texto possui uma cor.
A sua cor é representada por cor.
O texto é desenhado em um arquivo svg
*/

typedef struct texto Texto;

Texto* criartxt(int id, double x, double y, char *conteudo, char *cor);
/*
    @brief Cria um texto com os parâmetros passados
    @param id Identificador do texto
    @param x Coordenada x da posição do texto
    @param y Coordenada y da posição do texto
    @param conteudo Conteúdo textual do texto
    @param cor Cor do texto
    @return Retorna um ponteiro para o texto criado
*/

int obter_id_txt(Texto *t);
/*
    @brief Obtém o id do texto
    @param t Ponteiro para o texto
    @return Retorna o id do texto
*/

double obter_x_txt(Texto *t);
/*
    @brief Obtém a coordenada x da posição do texto
    @param t Ponteiro para o texto
    @return Retorna a coordenada x da posição do texto
*/

double obter_y_txt(Texto *t);
/*
    @brief Obtém a coordenada y da posição do texto
    @param t Ponteiro para o texto
    @return Retorna a coordenada y da posição do texto
*/

char* obter_conteudo_txt(Texto *t);
/*
    @brief Obtém o conteúdo do texto
    @param t Ponteiro para o texto
    @return Retorna o conteúdo do texto
*/

char* obter_cor_txt(Texto *t);
/*
    @brief Obtém a cor do texto
    @param t Ponteiro para o texto
    @return Retorna a cor do texto
*/

void liberar_txt(Texto *t);
/*
    @brief Libera a memória ocupada pelo texto
    @param t Ponteiro para o texto
*/

double calcular_area_txt(Texto *t);
/*
    @brief Calcula a área do texto
    @param t Ponteiro para o texto
    @return Retorna a área do texto (sempre 0.0, pois texto não tem área)
*/

double calcular_perimetro_txt(Texto *t);
/*
    @brief Calcula o perímetro do texto
    @param t Ponteiro para o texto
    @return Retorna o perímetro do texto (sempre 0.0, pois texto não tem perímetro)
*/

#endif
/*
    @brief: Finaliza o módulo de texto.
*/
