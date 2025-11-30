#ifndef circulo_h
#define circulo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Um círculo é uma forma geométrica definida por seu raio (r).
O círculo é representado por um ponto (x,y) que é o centro do círculo
e por seu raio (r), além disso o círculo possui uma borda e um preenchimento.
A sua cor de borda é representada por corb e de preenchimento por corp.
A área do círculo é dada por π*r²
O perímetro do círculo é dado por 2*π*r
O círculo é desenhado em um arquivo svg
*/

typedef void* Circulo;

Circulo criarcirculo(int id, double x, double y, double r, char *corb, char *corp);
/* @brief Cria um círculo com os parâmetros passados
* @param id Identificador do círculo
* @param x Coordenada x do centro do círculo
* @param y Coordenada y do centro do círculo
* @param r Raio do círculo
* @param corb Cor da borda do círculo
* @param corp Cor de preenchimento do círculo
* @return Retorna um ponteiro para o círculo criado
*/

int obteridcirculo(Circulo c);
/* @brief Obtém o id do círculo
* @param c Ponteiro para o círculo
* @return Retorna o id do círculo
*/

double obterxcirculo(Circulo c);
/* @brief Obtém a coordenada x do centro do círculo
* @param c Ponteiro para o círculo
* @return Retorna a coordenada x do centro do círculo
*/

double obterycirculo(Circulo c);
/* @brief Obtém a coordenada y do centro do círculo
* @param c Ponteiro para o círculo
* @return Retorna a coordenada y do centro do círculo
*/

double obterrcirculo(Circulo c);
/* @brief Obtém o raio do círculo
* @param c Ponteiro para o círculo
* @return Retorna o raio do círculo
*/

char* obtercorbcirculo(Circulo c);
/* @brief Obtém a cor da borda do círculo
* @param c Ponteiro para o círculo
* @return Retorna a cor da borda do círculo
*/

char* obtercorpcirculo(Circulo c);
/* @brief Obtém a cor de preenchimento do círculo
* @param c Ponteiro para o círculo
* @return Retorna a cor de preenchimento do círculo
*/

double obterareacirculo(Circulo c);
/* @brief Obtém a área do círculo
* @param c Ponteiro para o círculo
* @return Retorna a área do círculo
*/

double obterperimetrocirculo(Circulo c);
/* @brief Obtém o perímetro do círculo
* @param c Ponteiro para o círculo
* @return Retorna o perímetro do círculo
*/

void desenharcirculo(Circulo c, FILE* arq);
/* @brief Desenha o círculo em um arquivo svg
* @param c Ponteiro para o círculo
* @param arq Ponteiro para o arquivo svg
*/

void liberarcirculo(Circulo c);
/*
@brief Libera a memória alocada para o círculo
* @param c Ponteiro para o círculo
*/

#endif
/* @brief: Finaliza o módulo de círculo. */
