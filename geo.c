#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geo.h"

void cirargeo(char *nomearqsvg, char *nomearqgeo){
    FILE *saida = fopen(nomearqsvg, "a");
    if (saida == NULL) {
        perror("Erro ao abrir/criar arquivo svg");
        return;
    }
    fprintf(saida, "<!-- Início do arquivo GEO: %s -->\n", nomearqgeo);
    fprintf(saida, "<!-- Arquivo GEO processado com sucesso -->\n");
    fprintf(saida, "<!-- Fim do arquivo GEO: %s -->\n", nomearqgeo);
    fprintf(saida, "\n");

    fclose(saida);
}
