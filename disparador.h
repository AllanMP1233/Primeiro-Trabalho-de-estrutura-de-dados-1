#ifndef DISPARADOR_H
#define DISPARADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Disparador é o módulo responsável por gerenciar os disparadores do jogo Bocha Geométrica.
Cada disparador possui dois carregadores (esquerda e direita) implementados como pilhas,
e uma posição de disparo. O disparador pode carregar formas, selecionar cargas e executar disparos
em um ângulo específico, impulsionando formas pela arena.
*/

void criar_disparador(char *nomearqsvg, char *nomearqdisparador);
/*
    @brief: Cria um arquivo DISPARADOR com o nome especificado
    @param nomearqsvg: Nome do arquivo SVG de saída
    @param nomearqdisparador: Nome do arquivo DISPARADOR de entrada
*/

int adicionar_disparador(int id, double x, double y, double angulo);
/*
    @brief: Adiciona um novo disparador ao sistema
    @param id: Identificador único do disparador
    @param x: Coordenada x da posição do disparador na arena
    @param y: Coordenada y da posição do disparador na arena
    @param angulo: Ângulo de disparo em graus (0-360)
    @return: Índice do disparador no array, ou -1 em caso de erro
*/

bool carregar_forma(int disp_id, char lado, void *forma, char tipo);
/*
    @brief: Carrega uma forma em um dos carregadores do disparador
    @param disp_id: ID do disparador
    @param lado: Lado do carregador ('d' para direita, 'e' para esquerda)
    @param forma: Ponteiro para a forma geométrica a ser carregada
    @param tipo: Tipo da forma ('c' para círculo, 'r' para retângulo)
    @return: true se o carregamento foi bem-sucedido, false caso contrário
*/

bool selecionar_carga(int disp_id, char lado);
/*
    @brief: Seleciona uma carga de um carregador e coloca na posição de disparo
    @param disp_id: ID do disparador
    @param lado: Lado do carregador ('d' para direita, 'e' para esquerda)
    @return: true se a seleção foi bem-sucedida, false caso contrário
    @note: Se já houver uma carga em posição de disparo, ela é movida para o carregador esquerdo
*/

void* executar_disparo(int disp_id, double *novo_x, double *novo_y);
/*
    @brief: Executa o disparo da forma que está na posição de disparo
    @param disp_id: ID do disparador
    @param novo_x: Ponteiro para armazenar a nova coordenada x da forma após o disparo
    @param novo_y: Ponteiro para armazenar a nova coordenada y da forma após o disparo
    @return: Ponteiro para a forma disparada, ou NULL se não houver carga
    @note: A forma é removida da posição de disparo e suas coordenadas são calculadas
           com base no ângulo e velocidade do disparador
*/

void* clonar_forma(void *forma, char tipo);
/*
    @brief: Cria uma cópia idêntica de uma forma geométrica
    @param forma: Ponteiro para a forma a ser clonada
    @param tipo: Tipo da forma ('c' para círculo, 'r' para retângulo)
    @return: Ponteiro para a nova forma clonada, ou NULL em caso de erro
    @note: O clone possui os mesmos atributos da forma original (posição, dimensões, cores)
*/

void liberar_disparadores();
/*
    @brief: Libera toda a memória alocada para os disparadores e suas estruturas
    @note: Deve ser chamada ao final do programa para evitar vazamento de memória
*/

#endif
/*
    @brief: Finaliza o módulo de disparador
*/
