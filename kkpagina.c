#include<stdio.h>
#include<stdlib.h>
typedef int Item;
#define less(A,B) ((A) < (B))
#define troca(A,B) { Item t; t=A;A=B;B=t; }
#define medianaDe3(A,B) { if (less(B,A)) troca(A,B); }

int separa(int *v,int esquerda,int direita) {
  int c = v[direita];
  int j = esquerda;
  int aux;
  for(int k=esquerda;k<direita;k++)
    if(v[k]<c) {
        aux=v[k];
        v[k]=v[j];
        v[j]=aux;
        j++;
    }
    aux=v[j];
    v[j]=v[direita];
    v[direita]=aux;
    return j;
}

void quicksortM3(Item *v,int esquerda, int direita) {
    if (direita<=esquerda) return;

    medianaDe3(v[(esquerda+direita)/2],v[direita]);
    medianaDe3(v[esquerda],v[(esquerda+direita)/2]);
    medianaDe3(v[direita],v[(esquerda+direita)/2]);

  int j = separa(v,esquerda,direita);
  quicksortM3(v,esquerda,j-1);
  quicksortM3(v,j+1,direita);
}

void quickSelect(int *v,int esquerda, int direita, int k){
    int i;
    i= separa(v,esquerda,direita);
    if(direita<=esquerda)return;
    if(i>k)quickSelect(v,esquerda,i-1,k);
    if(i<k)quickSelect(v,i+1,direita,k);
}

int main() {
    int n,p,x;
    scanf("%d %d %d", &n, &p, &x);
    int v[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int inicioPagina = x * p;

    quickSelect(v, 0, n-1, inicioPagina);
    quickSelect(v, inicioPagina + 1, n - 1, inicioPagina + x - 1);
    quicksortM3(v,inicioPagina,inicioPagina+x-1);

    for(int j = inicioPagina; j <= inicioPagina + x - 1; j++){
        printf("%d\n", v[j]);
    }
}





