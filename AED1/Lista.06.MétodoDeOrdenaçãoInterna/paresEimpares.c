#include<stdio.h>
#include<stdlib.h>

int main()
{

    unsigned int n, P = 0, I = 0, i, j, aux;

    scanf("%u",&n);

    unsigned int imp[n], par[n];

    while(n--) {
        scanf("%u",&aux);

        if(aux %2 == 0) {
            par[P] = aux;
            P++;
        }else {
            imp[I] = aux;
            I++;
        }
    }

    for(i = 0; i < P; i++)
        {
          for(j = i + 1; j < P; j++)
          {
              if(par[i] > par[j]) {

                  aux = par[i];
                  par[i] = par[j];
                  par[j] = aux;
              }
          }
        }

        for(i = 0; i < I; i++)
        {
          for(j = i + 1; j < I; j++)
          {
              if(imp[i] < imp[j]) {

                  aux = imp[i];
                  imp[i] = imp[j];
                  imp[j] = aux;
              }
          }
        }

        for(i = 0; i < P; i++)
        {
            printf("%u ",par[i]);
        }
        printf("\n");
        for(j = 0; j < I; j++)
        {
            printf("%u ",imp[j]);
        }
        printf("\n");

    return (0);
}