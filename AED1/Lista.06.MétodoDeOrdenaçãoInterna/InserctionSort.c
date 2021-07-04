#include<stdio.h>
#include<stdlib.h>


int insertionSort( int v[], int n ) {
    int i, j, aux, count = 0;

    i = 0;
    j = 1;
    aux = 0;
    while (j < n) {
        aux = v[j];
        i = j - 1;

        while ((i >= 0) && (v[i] > aux)) {
            v[i + 1] = v[i];
            count++;
            i--; 
        }
        v[i + 1] = aux;
        j++; 
        count++;
    }

    return(count);
 }

 int selectionSort(int v[], int n) {
    int i, j, min, aux, count = 0;

    for (i = 0; (i < (n-1)); i++) {
        min = i;
        for (j = (i+1); (j < n); j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (v[i] != v[min]) {
        troca(&v[i], &v[min]);
        count++;
        }
    }

    return(count);
}

void troca (int * a, int * b) {
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    unsigned int N, i, sel, inse;

    scanf("%u",&N);

    int vetor[N];

    for(i = 0; i < N; i++) {
        scanf("%d",&vetor[i]);
    }

    inse = insertionSort(vetor, N);
    sel = selectionSort(vetor, N);

    printf("%u\n",(inse-sel));

    return(0);
}