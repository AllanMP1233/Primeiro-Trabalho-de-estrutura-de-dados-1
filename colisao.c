#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "colisao.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void cirarcolisao(char *nomearqsvg, char *nomearqcolisao){
    FILE *saida = fopen(nomearqsvg, "a");
    if (saida == NULL) return;
    fprintf(saida, "%s\n\n", nomearqcolisao);
    fprintf(saida, "\n");
    fprintf(saida, "%s\n", nomearqcolisao);
    fclose(saida);
}

bool verificar_colisao_circulos(double x1, double y1, double r1, double x2, double y2, double r2){
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx*dx + dy*dy);
    return d < (r1 + r2);
}

bool verificar_colisao_retangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2){
    return (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2);
}

bool verificar_colisao_circulo_retangulo(double cx, double cy, double cr, double rx, double ry, double rw, double rh){
    double tx = cx;
    double ty = cy;
    if (cx < rx) tx = rx;
    else if (cx > rx + rw) tx = rx + rw;
    if (cy < ry) ty = ry;
    else if (cy > ry + rh) ty = ry + rh;
    double dx = cx - tx;
    double dy = cy - ty;
    return (dx*dx + dy*dy) <= (cr*cr);
}

double calcular_area_intersecao_circulos(double x1, double y1, double r1, double x2, double y2, double r2){
    double d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    if(d >= r1+r2) return 0.0;
    if(d <= fabs(r1-r2)) { double minr = (r1<r2)?r1:r2; return M_PI*minr*minr; }
    double r1sq = r1*r1; double r2sq = r2*r2;
    double a = acos((r1sq+d*d-r2sq)/(2*r1*d));
    double b = acos((r2sq+d*d-r1sq)/(2*r2*d));
    return r1sq*a + r2sq*b - 0.5*(r1sq*sin(2*a) + r2sq*sin(2*b));
}

double calcular_area_intersecao_retangulos(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2){
    double ox = fmax(0, fmin(x1+w1, x2+w2) - fmax(x1, x2));
    double oy = fmax(0, fmin(y1+h1, y2+h2) - fmax(y1, y2));
    return ox * oy;
}