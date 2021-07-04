#include<stdio.h>
#include<stdlib.h>

int main()
{
    int over, A, B;
    char operador;

    scanf("%d",&over);
   // do{
        scanf("%d %c %d",&A, &operador, &B);
    //}while (operador != 'x' || operador != '+');

    
    switch (operador)
    {
    case 'x':
        A = A * B;
        break;

    case '+':
       A = A + B;
       break;
    
    default:
        break;
    }

    if(A > over)
    {
        printf("overflow");
    }else
    {
        printf("no overflow");
    }

    return 0;
}