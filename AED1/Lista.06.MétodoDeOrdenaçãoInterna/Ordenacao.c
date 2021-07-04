#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int N, i, j, L, K, aux;

    scanf("%u",&N);

    unsigned int vetor[N];

    for(i = 0; i < N; i++) {
        scanf("%u",&vetor[i]);
    }

    scanf("%u %u",&L, &K);

    for(i = 0; i < N; i++)
    {
        for(j = i + 1; j < N; j++)
        {
            if(vetor[i] >vetor[j]) {

                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    printf("%u\n",(vetor[L-1]+vetor[K-1]));
}