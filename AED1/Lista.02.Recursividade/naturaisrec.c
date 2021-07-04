#include<stdio.h>
#include<stdlib.h>

unsigned int recursao_natural(int n, int x)
{
    if(x <= n)
    {
        printf("%d ", x);
        return(recursao_natural(n, x+1));
    }

     return(n);

}

int main()
{
    int N, x = 1;

    do{
        scanf("%d",&N);
    }while(N < 0 || N > 5000);

    x = recursao_natural(N, x);

    return 0;
}