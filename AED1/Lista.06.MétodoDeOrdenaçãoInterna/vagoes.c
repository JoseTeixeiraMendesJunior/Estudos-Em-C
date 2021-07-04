#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int n, L, vet[1000], i, aux, count, j;

    scanf("%u",&n);

    while (n--)
    {
        count = 0;

        scanf("%u",&L);

        for(i = 0; i < L; i++)
        {
            scanf("%u",&vet[i]);
        }


        for(i = 0; i < L; i++)
        {
          for(j = i + 1; j < L; j++)
          {
              if(vet[i] > vet[j]) {

                  aux = vet[i];
                  vet[i] = vet[j];
                  vet[j] = aux;
                  count++;
              }
          }
        }

        printf("%u\n",count);
    }
    
    return (0);
}