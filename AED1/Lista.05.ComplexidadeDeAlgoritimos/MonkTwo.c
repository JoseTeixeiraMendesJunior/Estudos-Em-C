#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int A, B, C, K, T, aux;

    scanf("%u",&T);

    while (T--)
    {
        aux = 0;

        scanf("%d %d %d %d",&A, &B, &C, &K);

        while(((A *  pow(aux,2)) + (B * aux) + C) < K)
        {
            aux++;
        }

        printf("%d\n",aux);
    }
    
    return (0);
}