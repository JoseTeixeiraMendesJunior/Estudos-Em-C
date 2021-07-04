#include<stdio.h>
#include<stdlib.h>

long long int convertep_binario(unsigned long long int n)
{
    if(n < 2)
    {
        return(n);
    }
    if(n >= 2)
    {     
       return((n%2)+(10*convertep_binario(n/2)));
    }
}

int main()
{
    int casos;
    unsigned long long int decimal;

    do
    {
        scanf("%d",&casos);
    }while(casos < 1 || casos > 1000);

    while(casos--)
    { 
        do
        {
            scanf("%llu",&decimal);
        }while(casos < 0 || casos > 10000000);

        printf("%llu\n",convertep_binario(decimal));
        
    }

    return 0;
}