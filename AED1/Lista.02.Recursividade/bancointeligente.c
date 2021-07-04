#include<stdlib.h>
#include<stdio.h>

int controla_notas(int saque, int N2, int N5, int N10, int N20, int N50, int N100, int contador)
{
 
}

int banco(int s, int n2, int n5, int n10, int n20, int n50, int n100)
{
    if(s == 0)
    {
        return(1);
    }
    else if(s >= 100 && n100 > 0)
    {
        return(banco(s-100, n2, n5, n10, n20, n50, n100-1));
    }
    else if(s >= 50 && n50 > 0)
    {
        return(banco(s-50, n2, n5, n10, n20, n50-1, n100));
    }
    else if(s >= 20 && n20 > 0)
    {
        return(banco(s-20, n2, n5, n10, n20-1, n50, n100));
    }
    else if(s >= 10 && n10 > 0)
    {
        return(banco(s-10, n2, n5, n10-1, n20, n50, n100));
    }
    else if(s >= 5 && n5 > 0)
    {
        return(banco(s-5, n2, n5-1, n10, n20, n50, n100));
    }
    else if(s >= 2 && n2 > 0)
    {
        return(banco(s-2, n2-1, n5, n10, n20, n50, n100));
    }else{
        return(0);
    }
    
}

int main()
{
    int saque, N2, N5, N10, N20, N50, N100, contador = 0,aux;


    scanf("%d",&saque);

    scanf("%d %d %d %d %d %d",&N2, &N5, &N10, &N20, &N50, &N100);

    if(saque == 0)
    {
        printf("0");
        return 0;
    }

    contador += banco(saque,N2, 0, 0, 0, 0, 0);
    if(saque >= 5 && N5 > 0)
    {
        contador += banco(saque,N2, 1, 0, 0, 0, 0);
        if(saque >= 10 && N5 > 1)
        {
            contador += banco(saque,N2, N5, 0, 0, 0, 0);
        }
    }
    if(saque >= 10 && N10 > 0)
    {
        contador += banco(saque,N2, N5, 1, 0, 0, 0);
        if(saque >= 20 && N10 > 1)
        {
            contador += banco(saque,N2, N5, N10, 0, 0, 0);
            contador += banco(saque,N2, 0, N10, 0, 0, 0);
        }
    }
    if(saque >= 20 && N20 > 0)
    {
        contador += banco(saque,N2, N5, N10, 1, 0, 0);
        if(saque >= 40 && N20 > 1)
        {
            contador += banco(saque,N2, N5, N10, N20, 0, 0);
            contador += banco(saque,N2, N5, 0, N20, 0, 0);
            contador += banco(saque,N2, 0, 0, N20, 0, 0);

        }
    }
    if(saque >= 50 && N50 > 0)
    {
        contador += banco(saque,N2, N5, N10, N20, 1, 0);
        if(saque >=100 && N50 > 1)
        {
            contador += banco(saque,N2, N5, N10, N20, N50, 0);
            contador += banco(saque,N2, N5, N10, 0, N50, 0);
            contador += banco(saque,N2, N5, 0, 0, N50, 0);
            contador += banco(saque,N2, 0, 0, 0, N50, 0);
        }
    }
    if(saque >= 100 && N100 > 0)
    {
        contador += banco(saque,N2, N5, N10, N20, N50, 1);
        if(saque >= 200 && N100 >1)
        contador += banco(saque,N2, N5, N10, N20, N50, N100);
        contador += banco(saque,N2, N5, N10, N20, 0, N100);
        contador += banco(saque,N2, N5, N10, 0, 0, N100);
        contador += banco(saque,N2, N5, 0, 0, 0, N100);
        contador += banco(saque,N2, 0, 0, 0, 0, N100);
    }


    printf("%d",contador);

    return 0;
}

/*
 aux = N100;
    while(N100 > 0)
    {
        contador += banco(saque,N2,N5,N10,N20,N50,N100);
        N100--;
    }
    N100 = aux;

    aux = N50;
    while(N50--)
    {
        contador += banco(saque,N2,N5,N10,N20,N50,N100);
    }
    N50 = aux;

    aux = N20;
    while(N20--)
    {
        contador += banco(saque,N2,N5,N10,N20,N50,N100);
    }
    N20 = aux;

    aux = N10;
    while(N10--)
    {
        contador += banco(saque,N2,N5,N10,N20,N50,N100);
    }
    N10 = aux;

    aux = N5;
    while(N5--)
    {
        contador += banco(saque,N2,N5,N10,N20,N50,N100);
    }
    N5 = aux;
    
    aux = N2;
    while(N2--)
    {
        contador += banco(saque,N2,N5,N10,N20,N50,N100);
    }
    N2 = aux;
    */