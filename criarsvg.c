#include "criarsvg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void iniciasvg(char *nomearqsvg, double largura, double altura){
    FILE *saida = fopen(nomearqsvg, "w");
    if (saida == NULL) {
        perror("Erro ao abrir/criar arquivo svg");
        return;
    }
    fprintf(saida, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%.2lf\" height=\"%.2lf\">\n", largura, altura);
    fclose(saida);
}

void finalizarsvg(char *nomearqsvg){
    FILE *saida = fopen(nomearqsvg, "a");
    if (saida == NULL) {
        perror("Erro ao abrir/criar arquivo svg");
        return;
    }
    fprintf(saida, "</svg>\n");
    fclose(saida);
}
