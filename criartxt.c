#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criartxt.h"

void criartxt(int id, double x, double y, char *conteudo, char *cor){
    FILE *saida = fopen("saida.txt", "a");
    if (saida == NULL) {
        perror("Erro ao abrir/criar arquivo saida.txt");
        return;
    }

    fprintf(saida, "Tipo de Forma: Texto\n");
    fprintf(saida, "ID: %d\n", id);
    fprintf(saida, "COORDENADAS: X->%.2lf, Y->%.2lf\n", x, y);
    fprintf(saida, "Cor: %s\n", (cor != NULL ? cor : "N/A"));
    fprintf(saida, "Conteúdo do Texto: %s\n", (conteudo != NULL ? conteudo : ""));
    fprintf(saida, "\n");

    fclose(saida);
}
