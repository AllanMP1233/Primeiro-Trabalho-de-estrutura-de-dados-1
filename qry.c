#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"

void criararquivoqry(char *nomearqsvg, char *nomearqqry){
    FILE *saida = fopen(nomearqsvg, "a");
    if (saida == NULL) return;
    fprintf(saida, "\n\n", nomearqqry);
    fclose(saida);
}