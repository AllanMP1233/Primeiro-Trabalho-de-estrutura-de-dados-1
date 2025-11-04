#include "movimento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void mover_forma_na_arena(void *forma, char tipo_forma, double novo_x, double novo_y, void *arena){
    if (!forma && !arena) return;

    if (!arena) {
        switch (tipo_forma) {
            case 'c':
            {
                typedef struct { double x, y, r; } MovCirculo;
                MovCirculo *c = (MovCirculo*) forma;
                if (c) { c->x = novo_x; c->y = novo_y; }
                break;
            }

            case 'r':
            {
                typedef struct { double x, y, w, h; } MovRetangulo;
                MovRetangulo *r = (MovRetangulo*) forma;
                if (r) { r->x = novo_x; r->y = novo_y; }
                break;
            }

            case 'l':
            {
                typedef struct { double x1, y1, x2, y2; } MovLinha;
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
                typedef struct { double x, y; } MovTexto;
                MovTexto *t = (MovTexto*) forma;
                if (t) { t->x = novo_x; t->y = novo_y; }
                break;
            }

            default:
                break;
        }
        return;
    }

    typedef struct {
        void **formas;
        char  *tipos;
        size_t n;
    } Arena;

    Arena *a = (Arena*) arena;
    if (!a) return;

    for (size_t i = 0; i < a->n; ++i) {
        void *f = a->formas[i];
        char t = a->tipos ? a->tipos[i] : '\0';
        if (!f) continue;

        switch (t) {
            case 'c':
            {
                typedef struct { double x, y, r; } MovCirculo;
                MovCirculo *c = (MovCirculo*) f;
                if (c) { c->x = novo_x; c->y = novo_y; }
                break;
            }
            case 'r':
            {
                typedef struct { double x, y, w, h; } MovRetangulo;
                MovRetangulo *r = (MovRetangulo*) f;
                if (r) { r->x = novo_x; r->y = novo_y; }
                break;
            }
            case 'l':
            {
                typedef struct { double x1, y1, x2, y2; } MovLinha;
                MovLinha *l = (MovLinha*) f;
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
                typedef struct { double x, y; } MovTexto;
                MovTexto *tx = (MovTexto*) f;
                if (tx) { tx->x = novo_x; tx->y = novo_y; }
                break;
            }
            default:
                break;
        }
    }
}
