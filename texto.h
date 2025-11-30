#ifndef TEXTO_H
#define TEXTO_H

typedef struct texto Texto;

void* criartxt(int id, double x, double y, char *conteudo, char *corb);
/*
    @brief Aloca e cria uma estrutura de Texto na memória.
    @param id Identificador único.
    @param x Coordenada X.
    @param y Coordenada Y.
    @param conteudo String do texto.
    @param corb Cor da borda/texto.
    @return Ponteiro void* para a estrutura criada.
*/

double obter_x_txt(void *t);
/*
    @brief Retorna a coordenada X do texto.
*/

double obter_y_txt(void *t);
/*
    @brief Retorna a coordenada Y do texto.
*/

char* obter_conteudo_txt(void *t);
/*
    @brief Retorna o conteúdo string do texto.
*/

void liberar_texto(void *t);
/*
    @brief Libera a memória da estrutura Texto.
*/

#endif