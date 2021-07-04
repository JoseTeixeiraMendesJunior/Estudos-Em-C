#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    unsigned int N, i, produto = 1;

    scanf("%u",&N);

    unsigned int vet[N];
    float Pmin;

    for(i = 0; i < N; i++)
    {
        scanf("%u",&vet[i]);
        produto *= vet[i];
    }

    Pmin = pow(produto, 1.0/N) + 1;
    

    for(i = 0; i < N; i++)
    {
        printf("%.0f ",Pmin);
    }
    
    return (0);
}