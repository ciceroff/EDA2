#include <stdio.h>
#include <stdlib.h>


void intercala(int *vetorFinal, int tamanhoTotal, int *vetor, int tamanhoParcial) {
    int *temp = (int *)malloc((tamanhoTotal + tamanhoParcial) * sizeof(int));
    int i = 0, j = 0, k = 0;
    for (; i < tamanhoTotal && j < tamanhoParcial; k++)
    {
        if (vetorFinal[i] <= vetor[j])
            temp[k] = vetorFinal[i++];
        else
            temp[k] = vetor[j++];
    }

    while (i < tamanhoTotal)
        temp[k++] = vetorFinal[i++];
    while (j < tamanhoParcial)
        temp[k++] = vetor[j++];

    for (k = 0, i = 0; i < (tamanhoTotal + tamanhoParcial); i++, k++)
        vetorFinal[i] = temp[k];

    free(temp);
}


int main()
{
    int vetorFinal[800000], vetor[100000];
    int tamanhoTotal = 0;
    for (int i = 0; i < 8; i++)
    {
        int tamanho = 0;
        scanf(" %d", &tamanho);
        for (int j = 0; j < tamanho; j++) {
            scanf(" %d", &vetor[j]);
        }
        intercala(vetorFinal, tamanhoTotal, vetor, tamanho);
        tamanhoTotal += tamanho;
    }

    for (int i = 0; i < tamanhoTotal; i++) {
        printf("%d%c", vetorFinal[i], (i == tamanhoTotal - 1 ? '\n' : ' '));
    }
    
    return 0;
}