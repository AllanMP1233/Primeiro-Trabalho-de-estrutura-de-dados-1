#ifndef DISPARADOR_H
#define DISPARADOR_H

#include <stdbool.h>

void desenhar_disparador_svg(char *nomearqsvg, double x, double y, double angulo, int id);
/*
    @brief Desenha o disparador (quadrado verde e canhao) no SVG.
    @param nomearqsvg Nome do arquivo.
    @param x Posicao X.
    @param y Posicao Y.
    @param angulo Angulo do canhao.
    @param id ID para texto.
*/

int adicionar_disparador(int id, double x, double y, double angulo);
/*
    @brief Cria o disparador na memoria.
*/

int buscar_disparador_por_id(int id_real);
/*
    @brief Busca o indice interno pelo ID do GEO.
*/

bool obter_dados_disparador(int indice, double *x, double *y, double *ang, int *id_real);
/*
    @brief Retorna dados de posicao e angulo.
*/

bool carregar_forma(int indice, char lado, void *forma, char tipo);
/*
    @brief Carrega municao.
*/

bool selecionar_carga(int indice, char lado);
/*
    @brief Prepara municao.
*/

void* executar_disparo(int indice, double *novo_x, double *novo_y);
/*
    @brief Calcula o tiro.
*/

void* clonar_forma(void *forma, char tipo);
/*
    @brief Copia a forma.
*/

void liberar_disparadores(void);
/*
    @brief Limpa memoria.
*/

#endif