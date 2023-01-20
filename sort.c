#include <stdio.h>
#include <stdlib.h>

void insert_sort(int a[], int n){
    int i, j, x;

    for(i = 1; i < n; i++) {
        j=i-1;
        x=a[i];

        while(j>0 && a[j]>x) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

int main() {
    int i;
    int count = 1;
    int array[1000];
    while(scanf("%d", &i) == 1) {
        array[count] = i;
        count ++;
    }
   
    insert_sort(array, count);
    for (int i = 1; i < count; i++)
    {
        if(i == count - 1) {
            printf("%d\n", array[i]);
            return 0;
        }
        printf("%d ", array[i]);
        
    }
    return 0;
}