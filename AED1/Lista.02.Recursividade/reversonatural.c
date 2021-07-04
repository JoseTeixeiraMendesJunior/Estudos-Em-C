#include<stdio.h>
#include<stdlib.h>

int inverte_num(long int u)
{
    if(u%10 == 0)
        {
            return(inverte_num(u/10));
        }

    if(u < 10)
    {
        printf("%ld",u);
    }else
    {
        printf("%ld",u%10);
        inverte_num(u/10);
    }
}

int main()
{
    long int num;

    do
    {
        scanf("%ld",&num);
    }while(num < 1 || num > 10000000);

    inverte_num(num);

    return 0;
}