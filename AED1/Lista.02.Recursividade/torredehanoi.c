#include<stdio.h>
#include<stdlib.h>

void hanoi(int Discos, char O, char D, char A)
{
    if(Discos == 1)
    {
        printf("(%c,%c)\n",O,D);
        return;
    }

    hanoi(Discos-1,O,A,D);
    printf("(%c,%c)\n",O,D);
    hanoi(Discos-1,A,D,O);

}

int main()
{
    int discos;
    char origem = 'O', destino = 'D', auxiliar = 'A';

    do
    {
        scanf("%d",&discos);
    }while(discos < 2 || discos > 1000);

    hanoi(discos,origem,destino,auxiliar);
}