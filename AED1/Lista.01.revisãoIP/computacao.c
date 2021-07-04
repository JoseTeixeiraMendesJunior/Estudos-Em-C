#include<stdio.h>
#include<stdlib.h>

int numerico_tet(int n, int * num){
    int i = 0;
    
   while(n != 0)
   {
       num[i] = n%4;
       n = n/4;
       i++;
   }

   return(i);
}

int main()
{
    int n;
    int decimal, i, p;
    int numtet[50];
    char tetcha[50];

    do{
        scanf("%d",&n);
    }while(n < 1 || n > 100);

   
    
    while(n > 0)
    {
            n--;
            scanf("%d",&decimal);

    // transformar o num decimal em tetrade em forma numérica a priori.

    p = numerico_tet(decimal, &numtet);

    decimal = p - 1;


    for (i = 0 ; i < p; i++)
    {
        switch (numtet[i])
        {
        case 0:
            tetcha[decimal] = 'A';
            break;
            
        case 1:
            tetcha[decimal] = 'C'; 
            break;
        
        case 2:
            tetcha[decimal] = 'G';
            break;

        case 3:
            tetcha[decimal] = 'T';
            break;
        
        default:
            break;
        }
        decimal--;
    }

    for (i = 0; i < p; i++)
    {
        printf("%c",tetcha[i]);
    }
    printf("\n");
    
}

    
    
    return 0;
}