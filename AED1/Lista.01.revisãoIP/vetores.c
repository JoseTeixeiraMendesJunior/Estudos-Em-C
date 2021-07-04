#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void leitura_vetor()
{
    int i, j, sobe = 0, tam1, tam2, ni, nj;
    unsigned char A[200], B[200];
    unsigned char C[200] = {0};

    scanf("%s %s",A, B);

    tam1 = strlen(A);
    tam2 = strlen(B);

    for (i = tam2 - 1 ; i >= 0; i--)
    {
        ni = B[i] - '0';
        for (j = tam1 -1 ; j >= -1 ; j--)
        {

            if(j >= 0){
                nj = A[j] - '0';
            }
            else{
                nj = 0;
            }
            C[j+i+1] += nj * ni + sobe;
            sobe = C[j+i+1]/10;
            C[j+i+1] %= 10;
           
        }
    }

    C[tam1+tam2] = '\0';
    for(i = 0; i < tam1+tam2; i++){
        C[i] += '0';
    }

    if(C[0] == '0' && C[1] != '0')
    {
        for (i = 1; i < tam1+tam2; i++)
        {
            printf("%c",C[i]);
        }
        
    }else if(C[0] == '0' && C[1] == '0')
    {

        printf("0");

    }else
    {
        printf("%s", C);
    }

    printf("\n");
    


}

int main()
{
    int casos;

    do{
        scanf("%d",&casos);
    }while(casos < 1 || casos > 50);

    while(casos--)
    {
        leitura_vetor();
    }


    return 0;
}