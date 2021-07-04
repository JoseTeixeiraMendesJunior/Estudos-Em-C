#include<stdio.h>
#include<stdlib.h>


int main() 
{
    unsigned int t;
    int i, j;
    char instru[11][21];
    char rua[11][21];

    scanf("%u",&t);

    while(t--) {

        j = 0;
        
        for(i = 0; i < 10; i++) {

            scanf("%s",&instru[i]);
            scanf("%s",&rua[i]);

           if(rua[i] == 'ESCOLA') {
               break;
           }
        }


        for(i; i > -1; i--) {
            printf("Vire a ");

            if(instru[i] == "DIREITA") {

                printf("ESQUERDA ");
            }
            else {
                printf("DIREITA ");
            }
 
            if(i != 0) {
                printf("na rua %s.\n",rua[i-1]);
            }
            else {
                printf("na sua CASA.\n");
            }
        }
    }

    return (0);
}