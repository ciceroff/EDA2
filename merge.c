#include <stdio.h>
#include <stdlib.h>

void intercala (int *v, int esquerda, int meio, int direita) {
    int *v2 = malloc(sizeof(int) * (direita - esquerda + 1));
    int i = esquerda, j = meio + 1, k = 0;
    while(i <= meio && j <= direita) {
        if(v[i] <= v[j]) v2[k++] = v[i++];
        else v2[k++] = v[j++];
    }

    while(i <= meio) v2[k++] = v[i++];
    while(j <= direita) v2[k++] = v[j++];
    for(k = 0, i = esquerda; i <= direita; k++, i++) v[i] = v2[k];
}

void merge(int *v, int esquerda, int direita) {
    if(direita <= esquerda) return;
    int meio = (esquerda + direita)/2;

    merge(v, esquerda, meio);
    merge(v, meio + 1, direita);
    intercala(v, esquerda, meio, direita);
}

int main() {
    int array[100000];
    int i = 0;

    while(scanf("%d", &array[i]) != EOF) {
        i++;
    }

    merge(array, 0, i - 1);
    for(int j=0; j<i; j++) printf("%d%c", array[j], (j == i-1 ? '\n' : ' '));

    return 0;
}
