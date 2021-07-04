#include<stdio.h>
#include<stdlib.h>

void onde_esta_o_sapo(int * n, int j)
{
    int incial, pulo, esquerda, direita;

    scanf("%d %d",&incial, &pulo);

    incial--;

    esquerda = incial - pulo;

    direita =  incial + pulo;

    n[incial] = 1;

    while(esquerda >= 0)
            {
                n[esquerda] = 1;
                esquerda = esquerda - pulo;
            }

    while(direita < j)
            {
                n[direita] = 1;
                direita = direita + pulo;
                
            }
    


/*    for (i = 0; i < j; i++)
    {
        if(i == incial)
        {
            n[i] = 1;
        }else if(i == esquerda)
        {
            n[i] = 1;
            esquerda = esquerda - pulo;
            printf("%d\n",esquerda);
            while(esquerda >= 0)
            {
                n[esquerda] = 1;
                esquerda = esquerda - pulo;
            }
        }else if(i == pulo)
        {
            n[i] = 1;
            pulo = pulo + pulo;
            while(pulo < j)
            {
                printf("%d\n",pulo);
                n[pulo] = 1;
                pulo = pulo + pulo;
                
            }
        }
    }
    */
    
}


int main()
{
    int npedras, sapos;

    do{
        scanf("%d %d",&npedras, &sapos);
    }while((npedras < 1 || npedras > 50) && (sapos < 1 || sapos > 100));



    int pedras[npedras], i;

    for (i = 0; i < npedras; i++)
    {
        
        pedras[i] = 0;
    }
    
    

    while(sapos--)
    {
        onde_esta_o_sapo(&pedras, npedras);
    }


    
    for (i = 0; i < npedras; i++)
    {
        printf("%d\n",pedras[i]);
    }
    


    return 0;
}