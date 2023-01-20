#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    celula *prox = p->prox;
    if(prox){
        int x = p->prox->dado;
        p->prox = prox->prox;
        prox->prox = NULL;
        free(prox);
        return x;
    }
    return 0;
}

void remove_elemento (celula *le, int x) {
    celula *elem;
    
    for (elem=le; elem != NULL; elem = elem->prox) {
        if(elem->prox->dado == x) {
            celula *pop = elem->prox;
            elem->prox = pop->prox;
            pop->prox = NULL;
            free(pop);
            return;
        }
    }
}

void remove_todos_elementos (celula *le, int x) {
    celula *elem;
    
    for (elem=le; elem != NULL; elem = elem->prox) {
        if(elem->prox->dado == x) {
            celula *pop = elem->prox;
            elem->prox = pop->prox;
            pop->prox = NULL;
            free(pop);
        }
    }
}