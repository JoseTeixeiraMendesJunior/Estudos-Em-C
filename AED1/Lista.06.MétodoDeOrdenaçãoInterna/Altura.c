#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int N, h[100000], i, j, aux, tot;

    scanf("%u",&N);

    while (N--)
    {
        scanf("%u",&tot);

        for(i = 0; i < tot; i++) {
            scanf("%u",&h[i]);
        }

        for(i = 0; i < tot; i++)
        {
          for(j = i + 1; j < tot; j++)
          {
              if(h[i] > h[j]) {

                  aux = h[i];
                  h[i] = h[j];
                  h[j] = aux;
              }
          }
        }

        for(i = 0; i < tot; i++) {
            printf("%u ",h[i]);
        }
        printf("\n");
    }
    

    return(0);
}