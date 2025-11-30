#ifndef retangulo_h
#define retangulo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
Retângulo é uma forma geométrica definida por sua largura (l) e altura (h).
O retângulo é representado por um ponto (x,y) que é o canto inferior esquerdo do retângulo
e por sua largura (l) e altura (h), além disso o retângulo possui uma borda e um preenchimento.
A sua cor de borda é representada por corb e de preenchimento por corp.
A área do retângulo é dada por l*h
O perímetro do retângulo é dado por 2*(l+h)
O retângulo é desenhado em um arquivo svg
*/

typedef void* Rectan;

Rectan criarRetangulo(int id, double x, double y, double l, double h, char *corb, char *corp);
/* @brief Cria um retângulo com os parâmetros passados
 * @param id Identificador do retângulo
 * @param x Coordenada x do canto inferior esquerdo do retângulo
 * @param y Coordenada y do canto inferior esquerdo do retângulo
 * @param l Largura do retângulo
 * @param h Altura do retângulo
 * @param corb Cor da borda do retângulo
 * @param corp Cor de preenchimento do retângulo
 * @return Retorna um ponteiro para o retângulo criado
 */

int obter_id_ret(Rectan r);
/* @brief Obtém o id do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna o id do retângulo
 */

double obter_x_ret(Rectan r);
/* @brief Obtém a coordenada x do canto inferior esquerdo do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna a coordenada x do canto inferior esquerdo do retângulo
 */

double obter_y_ret(Rectan r);
/* @brief Obtém a coordenada y do canto inferior esquerdo do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna a coordenada y do canto inferior esquerdo do retângulo
 */

double obter_l_ret(Rectan r);
/* @brief Obtém a largura do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna a largura do retângulo
 */

double obter_h_ret(Rectan r);
/* @brief Obtém a altura do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna a altura do retângulo
 */

char* obter_corb_ret(Rectan r);
/* @brief Obtém a cor da borda do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna a cor da borda do retângulo
 */

char* obter_corp_ret(Rectan r);
/* @brief Obtém a cor de preenchimento do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna a cor de preenchimento do retângulo
 */

double obter_area_ret(Rectan r);
/* @brief Obtém a área do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna a área do retângulo
 */

double obter_perimetro_ret(Rectan r);
/* @brief Obtém o perímetro do retângulo
 * @param r Ponteiro para o retângulo
 * @return Retorna o perímetro do retângulo
 */

void desenhar_ret(Rectan r, FILE* arq);
/* @brief Desenha o retângulo em um arquivo svg
 * @param r Ponteiro para o retângulo
 * @param arq Ponteiro para o arquivo svg
 */

void liberar_ret(Rectan r);
/* @brief Libera a memória alocada para o retângulo
 * @param r Ponteiro para o retângulo
 */

#endif
/*
    @brief: Finaliza o módulo de retângulo.
*/
