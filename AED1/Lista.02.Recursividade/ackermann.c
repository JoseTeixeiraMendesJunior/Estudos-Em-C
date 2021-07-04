#include<stdio.h>
#include<stdlib.h>

int fun_alckerman(int m , int n)
{
    if(m == 0)
    {
        return(n+1);
    }

    if(m > 0 && n == 0)
    {
        return(fun_alckerman(m - 1, 1));
    }
    if(m > 0 && n > 0)
    {
        return(fun_alckerman(m - 1, fun_alckerman(m, n - 1)));
    }

}

int main()
{
    int m, n;

    scanf("%d %d",&m, &n);

    printf("%d\n",fun_alckerman(m, n));

    return 0;
}