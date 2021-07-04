#include<stdio.h>
#include<stdlib.h>

int conta_rotulos(int n[], int tp, int j)
{
    int i, cont , real = j;

    while(tp > 0)
    {
        cont = 0;

        for(i = 0; i < j; i++)
        {
            if(n[i] == tp)
            {
                cont++;
            }
        }
        if(real > cont)
        {
            real =cont;
        }

        tp--;
    }

    return(real);
}

int main()
{
    int N, tipos;

    do{
        scanf("%d %d",&N, &tipos);

    }while((N < 1 || N > 1000) && (tipos < 1 || tipos > 20));

    int seq[N], i;

    for(i = 0; i < N; i++)
    {
        do
        {
            scanf("%d",&seq[i]);
        } while (seq[i] < 1 || seq[i] > tipos);
    }

    N = conta_rotulos(seq, tipos, N);

    printf("%d",N);


    return 0;
}