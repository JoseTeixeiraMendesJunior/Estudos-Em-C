#include<stdio.h>
#include<stdlib.h>

int main() 
{
    unsigned int t, n, c, C[30000], i, m, a, b, tam, j, cont;

    scanf("%u",&t);

    while(t) {

        scanf("%u %u",&n, &c);

        for(i = 0; i < n; i++) {

            scanf("%u",&C[i]);
        }

        scanf("%u",&m);

        for(i = 0; i < m; i++) {

            j = 1;

            scanf("%u %u",&a, &b);

            tam = b - a + 1;
            tam /= 2;
            tam++;
            

            while(j <= c) {

                cont = 0;

                for(i = a-1; i < b; i++) {
                    
                    if(C[i] == j) {
                        cont++;
                    }
                }
                if(cont >= tam) {
                    break;
                }
            }

            if(j > c) {
                printf("feia\n");
            }
            else {
                printf("bonita %u\n",j);
            }
        }
        t--;
    }

    return (0);
}