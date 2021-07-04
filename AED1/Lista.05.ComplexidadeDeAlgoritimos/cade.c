#include<stdio.h>
#include<stdlib.h>

int main()
{  
    unsigned int n, aux, i = 0, dias, j;

    scanf("%u",&n);

    unsigned int valor[n], vaux[n];

    aux = n;

    while (aux--)
    {
        scanf("%u",&valor[i]);
        i++;
    }
    

    scanf("%u",&dias);

    aux = dias;
    i = 0;

    unsigned int moedas[dias];

    while (aux--)
    {
        scanf("%u",&moedas[i]);
        i++;
    }

    for(i = 0; i < dias; i++)
    {
        aux = 0;

        for(j = 0; j < n; j++)
        {
            if(moedas[i] >= valor[j])
            {
                vaux[aux] = j+1;
                aux++;

            }
        }

        printf("%u ",aux);

        if(aux > 0)
        {
            for(j = 0; j < aux; j++)
            {
                printf("%u ",vaux[j]);
            }
        }

        printf("\n");
    }
    

    return (0);
}