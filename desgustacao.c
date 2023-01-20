#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    int quantidade;
    char letra;
    int posicao;
} Item;

void intercala (Item *v, int esquerda, int meio, int direita) {
    Item *v2 = malloc(sizeof(Item) * (direita - esquerda + 1));
    int i = esquerda, j = meio + 1, k = 0;
    while(i <= meio && j <= direita) {
        if(v[i].quantidade < v[j].quantidade) v2[k++] = v[i++];
        else v2[k++] = v[j++];
    }

    while(i <= meio){ v2[k++] = v[i++];}
    while(j <= direita){ v2[k++] = v[j++];}
    for(k = 0, i = esquerda; i <= direita; k++, i++) v[i] = v2[k];
}

void merge(Item *v, int esquerda, int direita) {
    if(direita <= esquerda) return;
    int meio = (esquerda + direita)/2;

    merge(v, esquerda, meio);
    merge(v, meio + 1, direita);

    intercala(v, esquerda, meio, direita);
}

int main(int argc, char const *argv[]) {
    char string[100001];
    int tamanho = 0, quantidade = 0;
    int compara = 0;
    scanf("%s", string);
    Item item[strlen(string)];
    item[0].quantidade = 0;
    for (int i = 0; i < strlen(string); i++) {
        if(string[i] != string[compara]){
            compara = i;
            tamanho++;
            item[tamanho].quantidade=0;
        } 
        item[tamanho].quantidade++;
        item[tamanho].posicao = compara;
        item[tamanho].letra = string[compara];

    }
    
    merge(item, 0, tamanho);
    for (int i = tamanho; i >= 0; i--) {
        printf("%d %c %d\n", item[i].quantidade, item[i].letra, item[i].posicao);
    }

    return 0;
}
