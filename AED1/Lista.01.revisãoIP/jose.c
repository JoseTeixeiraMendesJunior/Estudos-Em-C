#include<stdio.h>
#include<stdlib.h>

int inverte(int n){
    int n1,n2;

    n1 = n/100;
    n = n%100;
    n2 = n/10;
    n = n%10;

    n = n*100+n2*10+n1;

    return(n);
}

int main(){
    
    int A, B;

    scanf("%d %d",&A, &B);

    A = inverte(A);
    B = inverte (B);

    if(A > B)
    {
        printf("%d",A);
    }else
    {
        printf("%d",B);
    }

    return 0;
}