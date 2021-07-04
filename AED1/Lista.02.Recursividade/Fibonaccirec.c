#include<stdio.h>
#include<stdlib.h>

long double fibonacci_pradireita (int n)
{
        
    

    if(n == 1)
    {
        return(1);
    }
    if(n == 2)
    {
        return(1);
    }
    
    if(n > 2)
    {

        return(fibonacci_pradireita(n - 1) + fibonacci_pradireita(n - 2));
        
    }

}

long double fibonacci(int n)
{
    double p;
    

    if(n == 1)
    {
        printf("1 ");
        return(1);
    }
    if(n == 2)
    {
        printf("1 1 ");
        return(1);
    }
    
    if(n > 2)
    {
        p = fibonacci(n - 1) + fibonacci_pradireita(n - 2);
        printf("%.0lf ", p);
        return(p);
        
    }
}

int main()
{
    int N;

    do
    {
        scanf("%d",&N);
    }while(N < 0 || N > 1000);

    printf("0 ");

    if(N == 0)
    {
        return 0;
    }

   // int fib[N];

   // fib[0] = 0;

    N = fibonacci(N);

    /*for (x = 0; x <= N; x++)
    {
        printf("%d ", fib[x]);
    }*/
    


    return 0;
}