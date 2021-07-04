#include<stdio.h>
#include<stdlib.h>

void primo()
{
    int i, cont = 0;
    int unsigned long num;

    scanf("%lu",&num);
    

    for (i = 1; i <= num; i++)
    {
        if(num%i == 0)
        {
            cont++;
        }
    }

    if(cont == 2)
    {
        printf("primo\n");
    }else
    {
        printf("composto\n");
    }
    

}

int main()
{
    int casos;

    scanf("%d",&casos);

    while(casos--)
    {
        primo();
    }


    return 0;
}