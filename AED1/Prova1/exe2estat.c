#include<stdio.h>
#include<stdlib.h>

//Ola professor, caso leia esse recado...
// tentei fazer de forma dinamica em outro arquivo q foi submetido ao sharif
// agradeceria se pudesse me guiar dos erros cometidos, Obrigado!

int main()
{
    unsigned int V1[2000], V2[2000], V3[2000], i, j, p, tam1, tam2, flag, check;
    long int codigo;

    for(i = 0; i < 2000; i++) {

        scanf("%ld",&codigo);

        if(codigo == -1) {
            break;
        }

        V1[i] = codigo;
    }
    tam1 = i;

    for(i = 0; i < 2000; i++) {

        scanf("%ld",&codigo);

        if(codigo == -1) {
            break;
        }

        V2[i] = codigo;
        
    }

    tam2 = i;

    for(i= 0; i < tam1; i++) {
        for(j = i+1; j < tam1; j++) {
            if(V1[i] > V1[j]) {
                flag = V1[i];
                V1[i] = V1[j];
                V1[j] = flag;
            }
        }
    }

    for(i= 0; i < tam2; i++) {
        for(j = i+1; j < tam2; j++) {
            if(V2[i] > V2[j]) {
                flag = V2[i];
                V2[i] = V2[j];
                V2[j] = flag;
            }
        }
    }


    for(i = 0; i < tam1; i++) 
    {
        for(j = i + 1; j < tam1;)
        {
            if(V1[j] == V1[i]) {
                for(p = j; p < tam1; p++)
                {
                    V1[p] = V1[p+1];
                }
                tam1--;
            }
            else {
                j++;
            }
        }

    }

    for(i = 0; i < tam2; i++) 
    {
        for(j = i + 1; j < tam2;)
        {
            if(V2[j] == V2[i]) {
                for(p = j; p < tam2; p++)
                {
                    V2[p] = V2[p+1];
                }

                tam2--;
            }
            else {
                j++;
            }
        }

    }

    if(tam1 == tam2) {
        check = 0;

        for(i = 0; i < tam1; i++) {
            if((V1[i]) != (V2[i])) {
                check = 1;
                break;
            }
        }

        if(check == 0) {
            printf("iguais %u\n",tam1);
            return(0);
        }
    }

    p = 0;

    for(i = 0; i < tam1; i++)
    {
        flag = 0;

        for(j = 0; j<tam2; j++)
        {
            if(V1[i] == V2[j]) {
                flag = 1;
            }
        }
        if(flag == 0) {
            V3[p] = V1[1];
        }
    }

    for(i = 0; i < tam2; i++)
    {
        flag = 0;

        for(j = 0; j<tam1; j++)
        {
            if(V2[i] == V1[j]) {
                flag = 1;
            }
        }
        if(flag == 0) {
            V3[p] = V1[1];
        }
    }

    p++;

    for(i= 0; i < p; i++) {
        for(j = i+1; j < p; j++) {
            if(V3[i] > V3[j]) {
                flag = V3[i];
                V3[i] = V3[j];
                V3[j] = flag;
            }
        }
    }
    
    printf("diferentes ");

    for(i = 0; i < p; i++){
        printf("%ld ",V3[i]);
    }
    return(0);
}