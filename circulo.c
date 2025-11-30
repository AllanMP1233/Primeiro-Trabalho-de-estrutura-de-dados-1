#include "circulo.h"

#define PI 3.14159

typedef struct circulo {
    int id;
    double x;
    double y;
    double r;
    char corb[20];
    char corp[20];
} CirculoStruct;

Circulo criarcirculo(int id, double x, double y, double r, char *corb, char *corp){
    CirculoStruct *c = (CirculoStruct *) malloc(sizeof(CirculoStruct));
    if (c == NULL) {
        printf("Erro ao alocar memória para o circulo.\n");
        exit(1);
    }

    c->id = id;
    c->x = x;
    c->y = y;
    c->r = r;
    strcpy(c->corb, corb);
    strcpy(c->corp, corp);

    return (Circulo) c;
}

int obteridcirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    return cc->id;
}

double obterxcirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    return cc->x;
}

double obterycirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    return cc->y;
}

double obterrcirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    return cc->r;
}

char* obtercorbcirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    return cc->corb;
}

char* obtercorpcirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    return cc->corp;
}

double obterareacirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    return PI * pow(cc->r, 2);
}

double obterperimetrocirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    return 2 * PI * cc->r;
}

void desenharcirculo(Circulo c, FILE* arq){
    CirculoStruct *cc = (CirculoStruct *) c;
    fprintf(arq,
            "ircle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\" />\n",
            cc->x, cc->y, cc->r, cc->corb, cc->corp);
}

void liberarcirculo(Circulo c){
    CirculoStruct *cc = (CirculoStruct *) c;
    free(cc);
}
