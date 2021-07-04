#include<stdio.h>
#include<stdlib.h>

int inverte(int n){
    int n1, n2, n3;

    n1 = n/1000;
    n = n%1000;
    n2 = n/100;
    n = n%100;
    n3 = n/10;
    n = n%10;

    n = n*1000+n3*100+n2*10+n1;

    return(n);
}

void palindromo(int n){
    int x;

    x = inverte(n);

    if(n == x)
    {
        printf("yes ");
    }else
    {
        printf("no ");
    }

}

int main()
{
    int N, num;

    scanf("%d",&N);

    while (N)
    {
        scanf("%d",&num);
    
        palindromo(num);

        N--;
    }
    
    return 0;
}