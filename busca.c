#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca (celula *le, int x) {
    celula *elem;
    
    for (elem=le; elem != NULL; elem = elem->prox) {
        if(elem->dado == x) {
            return elem;
        }
    }

    return NULL;
}

celula * busca_rec (celula *le, int x) {
    if (le != NULL) {
        if(le->dado == x) { 
            return le;
        }
        busca_rec(le->prox, x);
    } else { 
        return NULL;
    }  
}