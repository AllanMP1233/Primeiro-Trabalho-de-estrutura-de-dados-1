#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criartxt.h"

void gerartxt(char *nomearqtxt, int id, double x, double y, char *conteudo, char *cor){
    FILE *saida = fopen(nomearqtxt, "a");
    if (saida == NULL) return;

    fprintf(saida, "TEXTO ID: %d | Pos: (%.2lf, %.2lf) | Cor: %s | Conteudo: %s\n", 
            id, x, y, (cor ? cor : "N/A"), (conteudo ? conteudo : ""));

    fclose(saida);
}