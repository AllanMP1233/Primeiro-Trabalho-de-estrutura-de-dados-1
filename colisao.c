#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "colisao.h"
#include "circulo.h"
#include "retangulo.h"

void cirarcolisao(char *nomearqsvg, char *nomearqcolisao){
    FILE *saida = fopen(nomearqsvg, "a");
    if (saida == NULL) {
        perror("Erro ao abrir/criar arquivo svg");
        return;
    }
    fprintf(saida, "<!-- Início do arquivo COLISÃO: %s -->\n", nomearqcolisao);
    fprintf(saida, "<!-- Arquivo COLISÃO processado com sucesso -->\n");
    fprintf(saida, "<!-- Fim do arquivo COLISÃO: %s -->\n", nomearqcolisao);
    fclose(saida);
}

bool verificar_colisao_circulos(double x1, double y1, double r1, double x2, double y2, double r2){
    double dx = x2 - x1;
    double dy = y2 - y1;
    double distancia = sqrt(dx*dx + dy*dy);
    return distancia < (r1 + r2);
}

bool verificar_colisao_retangulos(double x1, double y1, double w1, double h1, 
                                   double x2, double y2, double w2, double h2){
    return !(x1 + w1 < x2 || x2 + w2 < x1 || y1 + h1 < y2 || y2 + h2 < y1);
}

bool verificar_colisao_circulo_retangulo(double cx, double cy, double r, 
                                          double rx, double ry, double w, double h){
    double closestX = fmax(rx, fmin(cx, rx + w));
    double closestY = fmax(ry, fmin(cy, ry + h));
    double dx = cx - closestX;
    double dy = cy - closestY;
    return (dx * dx + dy * dy) < (r * r);
}

double calcular_area_intersecao_circulos(double x1, double y1, double r1, 
                                          double x2, double y2, double r2){
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx*dx + dy*dy);
    
    if(d >= r1 + r2) return 0.0;
    if(d <= fabs(r1 - r2)) return M_PI * fmin(r1, r2) * fmin(r1, r2);
    
    double a1 = r1*r1 * acos((d*d + r1*r1 - r2*r2)/(2*d*r1));
    double a2 = r2*r2 * acos((d*d + r2*r2 - r1*r1)/(2*d*r2));
    double a3 = 0.5 * sqrt((-d+r1+r2)*(d+r1-r2)*(d-r1+r2)*(d+r1+r2));
    
    return a1 + a2 - a3;
}

double calcular_area_intersecao_retangulos(double x1, double y1, double w1, double h1,
                                            double x2, double y2, double w2, double h2){
    double x_overlap = fmax(0, fmin(x1 + w1, x2 + w2) - fmax(x1, x2));
    double y_overlap = fmax(0, fmin(y1 + h1, y2 + h2) - fmax(y1, y2));
    return x_overlap * y_overlap;
}

void mover_forma_na_arena(void *forma, char tipo_forma, double novo_x, double novo_y, void *arena){
    if (!forma) return;
    
    switch (tipo_forma) {
        case 'c':
        {
            typedef struct { int id; double x, y, r; } MovCirculo;
            MovCirculo *c = (MovCirculo*) forma;
            if (c) { c->x = novo_x; c->y = novo_y; }
            break;
        }
        case 'r':
        {
            typedef struct { int id; double x, y, w, h; } MovRetangulo;
            MovRetangulo *r = (MovRetangulo*) forma;
            if (r) { r->x = novo_x; r->y = novo_y; }
            break;
        }
        case 'l':
        {
            typedef struct { int id; double x1, y1, x2, y2; } MovLinha;
            MovLinha *l = (MovLinha*) forma;
            if (l) {
                double dx = novo_x - l->x1;
                double dy = novo_y - l->y1;
                l->x1 += dx; l->y1 += dy;
                l->x2 += dx; l->y2 += dy;
            }
            break;
        }
        default:
            break;
    }
}
