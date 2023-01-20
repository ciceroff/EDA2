#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
#define less(a, b) (a.value == b.value ? a.key > b.key : a.value > b.value)
#define swap(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }

typedef struct item{
    int key, value;
} Item;

void medianaDe3(Item a, Item b) {
    if (less(b, a))   
    swap(a, b)
}

int particiona(Item *v, int l, int r)
{
    Item pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivot))
        {
            swap(v[k], v[j]);
            j++;
        }
    swap(v[j], v[r]);
    return j;
}

void quicksort(Item *v, int l, int r) {
    if (r <= l)
        return;

    medianaDe3(v[(l + r) / 2], v[r]);
    medianaDe3(v[l], v[(l + r) / 2]);
    medianaDe3(v[r], v[(l + r) / 2]);

    int m = particiona(v, l, r);
    quicksort(v, l, m - 1);
    quicksort(v, m + 1, r);
}

Item arrayPresidentes[91], arraySenadores[901], arrayDeputadosFederais[9001], arrayDeputadosEstaduais[90001];
int presidente = 0, senadores = 0, deputadosFederais = 0, deputadosEstaduais = 0;

int main() {
    long long s, f, e;
    scanf(" %lld %lld %lld", &s, &f, &e);

    long long valid = 0, invalid = 0, totalPresidentes = 0;
    for (int x, l; scanf("%d%n", &x, &l) == 1;) {
        if (x < 0) {
            invalid++;
            continue;
        }

        switch (l) {
        case 3:
            arrayPresidentes[x - 10].key = x;
            arrayPresidentes[x - 10].value++;
            totalPresidentes++;
            break;
        case 4:
            arraySenadores[x - 100].key = x;
            arraySenadores[x - 100].value++;
            break;
        case 5:
            arrayDeputadosFederais[x - 1000].key = x;
            arrayDeputadosFederais[x - 1000].value++;
            break;
        default:
            arrayDeputadosEstaduais[x - 10000].key = x;
            arrayDeputadosEstaduais[x - 10000].value++;
        }
        valid++;
    }

    for (int i = 0; i < 91; i++)
        if (arrayPresidentes[i].value)
            arrayPresidentes[presidente++] = arrayPresidentes[i];
    for (int i = 0; i < 901; i++)
        if (arraySenadores[i].value)
            arraySenadores[senadores++] = arraySenadores[i];
    for (int i = 0; i < 9001; i++)
        if (arrayDeputadosFederais[i].value)
            arrayDeputadosFederais[deputadosFederais++] = arrayDeputadosFederais[i];
    for (int i = 0; i < 90001; i++)
        if (arrayDeputadosEstaduais[i].value)
            arrayDeputadosEstaduais[deputadosEstaduais++] = arrayDeputadosEstaduais[i];

    printf("%lld %lld\n", valid, invalid);

    quicksort(arrayPresidentes, 0, presidente - 1);
    quicksort(arraySenadores, 0, senadores - 1);
    quicksort(arrayDeputadosFederais, 0, deputadosFederais - 1);
    quicksort(arrayDeputadosEstaduais, 0, deputadosEstaduais - 1);

    if ((double)arrayPresidentes[0].value / totalPresidentes >= .51)
        printf("%d\n", arrayPresidentes[0].key);
    else
        printf("Segundo turno\n");

    for (int i = 0; i < s; i++) {
        printf("%d%c", arraySenadores[i].key, " \n"[i == s - 1]);
    }
    for (int i = 0; i < f; i++) {
        printf("%d%c", arrayDeputadosFederais[i].key, " \n"[i == f - 1]);
    }
    for (int i = 0; i < e; i++) {
        printf("%d%c", arrayDeputadosEstaduais[i].key, " \n"[i == e - 1]);
    }

    return 0;
}