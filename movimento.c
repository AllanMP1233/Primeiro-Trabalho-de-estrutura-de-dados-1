#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movimento.h"
#include "arena.h"

void mover_forma_na_arena(void *forma, char tipo_forma, double novo_x, double novo_y, ARENA *arena){
    if (!forma) return;
    (void)arena; 

    switch (tipo_forma) {
        case 'c':
        {
            typedef struct { int id; double x, y, r; char cb[20], cp[20]; } MovCirculo;
            MovCirculo *c = (MovCirculo*) forma;
            if (c) { c->x = novo_x; c->y = novo_y; }
            break;
        }
        case 'r':
        {
            typedef struct { int id; double x, y, w, h; char cb[20], cp[20]; } MovRetangulo;
            MovRetangulo *r = (MovRetangulo*) forma;
            if (r) { r->x = novo_x; r->y = novo_y; }
            break;
        }
        case 'l':
        {
            typedef struct { int id; double x1, y1, x2, y2; char c[20]; } MovLinha;
            MovLinha *l = (MovLinha*) forma;
            if (l) {
                double dx = novo_x - l->x1;
                double dy = novo_y - l->y1;
                l->x1 += dx; l->y1 += dy;
                l->x2 += dx; l->y2 += dy;
            }
            break;
        }
        case 't':
        {
            typedef struct { int id; double x, y; char cb[20], cp[20]; char anc; char txt[200]; } MovTexto;
            MovTexto *t = (MovTexto*) forma;
            if (t) { t->x = novo_x; t->y = novo_y; }
            break;
        }
        default:
            break;
    }
}