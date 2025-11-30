#include <stdio.h>
#include <stdlib.h>
#include "arena.h"

typedef struct {
    int id;
    void *forma;
    char tipo;
} ElementoArena;

/* A struct real só existe aqui dentro do .c */
typedef struct {
    ElementoArena elementos[1000];
    int qtd;
    int largura;
    int altura;
} ArenaInterna;

ARENA* criar_arena(int largura, int altura){
    ArenaInterna *a = (ArenaInterna*)malloc(sizeof(ArenaInterna));
    if(a){
        a->qtd = 0;
        a->largura = largura;
        a->altura = altura;
    }
    /* Retorna como (void*) para o header */
    return (ARENA*)a;
}

void adicionar_forma_arena(ARENA *arena, int id, void *forma, char tipo){
    if(!arena) return;
    
    /* Converte o ponteiro opaco para a struct interna */
    ArenaInterna *a = (ArenaInterna*)arena;

    if(a->qtd >= 1000) return;
    
    a->elementos[a->qtd].id = id;
    a->elementos[a->qtd].forma = forma;
    a->elementos[a->qtd].tipo = tipo;
    a->qtd++;
}

bool remover_forma_arena(ARENA *arena, int id){
    if(!arena) return false;
    
    ArenaInterna *a = (ArenaInterna*)arena;
    
    for(int i = 0; i < a->qtd; i++){
        if(a->elementos[i].id == id){
            a->elementos[i] = a->elementos[a->qtd - 1];
            a->qtd--;
            return true;
        }
    }
    return false;
}

void liberar_arena(ARENA *arena){
    if(arena){
        free(arena);
    }
}