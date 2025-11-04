#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "qry.h"

void criararquivoqry(char *nomearqsvg, char *nomearqqry){
    FILE *saida = fopen(nomearqsvg, "a");
    if (saida == NULL) {
        perror("Erro ao abrir/criar arquivo svg");
        return;
    }
    fprintf(saida, "<!-- Início do arquivo QRY: %s -->\n", nomearqqry);
    fprintf(saida, "<!-- Arquivo QRY processado com sucesso -->\n");
    fprintf(saida, "<!-- Fim do arquivo QRY: %s -->\n", nomearqqry);
    fprintf(saida, "\n");

    fclose(saida);
}
