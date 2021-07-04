#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int n, x, j;
    int i;

    scanf("%u",&n);

    char lista[n][31];
    unsigned int id[n];

    for(i = 0; i < n; i++) {

        scanf("%s %u",&lista[i], &id[i]);
    }

    x = id[1];
    i = x + 1;

    while(x--) {

        i++;

        if(i == n) {
            i = 0;
        }

    }

    j  = n - 1;

    while(j != 1) {

        x = id[i];
        id[i] = 501;

        if((x %= 2) != 0) {

                
            while(x--) {

                i++;

                if(i == n) {
                    i = 0;
                }

                if(id[i] == 501) {
                    x++;
                }

            }
        }
        else {

            
            while(x--) {

                i--;

                if(i == -1) {
                    i = n - 1;
                }

                if(id[i] == 501) {
                    x++;
                }

             }
        }


    j--;

    }

    i = 0;

    while(i == 501) {
        i++;
    }

    printf("%s\n",lista[i]);

    return (0);
}