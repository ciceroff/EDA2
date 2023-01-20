#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x) {
    celula *elem = malloc(sizeof(celula));
    elem->dado = x;
    elem->prox = le->prox;
    le->prox = elem;
}

void insere_antes(celula *le, int x, int y) {
    celula *elem;
    celula *insercao = malloc(sizeof(celula));
    
    insercao->dado = x;

    for (elem=le; elem->prox != NULL; elem = elem->prox) {
        if(elem->prox->dado == y) {
            insercao->prox = elem->prox;
            elem->prox=insercao;
            return;
        }
    }

    insercao->prox = elem->prox;
    elem->prox=insercao;
}