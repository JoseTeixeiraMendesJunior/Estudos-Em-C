#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int n, s, check;

    scanf("%u",&n);

    unsigned int fila[n], i, j;

    for(i = 0; i < n; i++) {

        scanf("%u",&fila[i]);
    }

    scanf("%u",&s);

    unsigned int sairam[s];

    for(i = 0; i < s; i++) {

        scanf("%u",&sairam[i]);
    }

    for(i = 0; i < n; i++) {
        check = 0;
        for(j = 0; j < s; j++) {
            if(fila[i] == sairam[j]) {
                check++;
            }
        }

        if(check == 0) {
            printf("%u ",fila[i]);
        }
    }

    return (0);
}