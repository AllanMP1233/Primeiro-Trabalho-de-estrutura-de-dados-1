#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159

struct circulo{
    int id;
    double x;
    double y;
    double r;
    char corb[20];
    char corp[20];
};

Circulo* criarcirculo(int id, double x, double y, double r, char *corb, char *corp){
    Circulo *c = (Circulo *)malloc(sizeof(Circulo));
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
    return c;
}

int obteridcirculo(Circulo* c){
    return c->id;
}

double obterxcirculo(Circulo* c){
    return c->x;
}

double obterycirculo(Circulo* c){
    return c->y;
}

double obterrcirculo(Circulo* c){
    return c->r;
}

char* obtercorbcirculo(Circulo* c){
    return c->corb;
}

char* obtercorpcirculo(Circulo* c){
    return c->corp;
}

double obterareacirculo(Circulo* c){
    return PI * pow(c->r, 2);
}

double obterperimetrocirculo(Circulo* c){
    return 2 * PI * c->r;
}

void desenharcirculo(Circulo* c, FILE* arq){
    fprintf(arq, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"%.2f\" stroke=\"%s\" fill=\"%s\" stroke-width=\"1\" />\n", 
            c->x, c->y, c->r, c->corb, c->corp);
}

void liberarcirculo(Circulo* c){
    free(c);
}
