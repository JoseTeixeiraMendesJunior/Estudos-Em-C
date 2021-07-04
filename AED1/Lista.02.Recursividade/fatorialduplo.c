#include<stdio.h>
#include<stdlib.h>

double duplo_fatorial(long long int n)
{
    if(n % 2 == 0)
    {
        return(duplo_fatorial(n-1));
    }
    if(n == 1)
    {
        return(1);
    }else
    {
        return(n * duplo_fatorial(n-2));
    }
}

int main()
{
    long long int num;

    do
    {
        scanf("%lld",&num);
    }while(num < 1 || num > 100);

    printf("%.0lf\n",duplo_fatorial(num));

    return 0;
}