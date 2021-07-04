#include <stdio.h>
 
typedef struct tempo{
    int hora;
    int minuto;
} Tempo;
 
 
void ordena(Tempo *horas, int tam){
    int i, j;
    Tempo aux;
    for(i = 0; i < tam; i++){
        for(j = i+1; j < tam; j++){
            if(horas[i].hora > horas[j].hora){
                aux = horas[i];
                horas[i] = horas[j];
                horas[j] = aux;
            }
        }
    }
}
 
void ordenaMinuto(Tempo *horas, int tam, int distintos){
    int num = horas[0].hora, i, j, k = 0;
    Tempo aux;
    while(distintos--){
        for(i = k; horas[i].hora == num; i++){
            for(j = i+1; horas[j].hora == num; j++){
                if(horas[i].minuto > horas[j].minuto){
                    aux = horas[i];
                    horas[i] = horas[j];
                    horas[j] = aux;
                }
            }
        }
        k = i;
        num = horas[i].hora;
    }
}
 
void somaMinuto(Tempo *horas, int distintos, int *maior, int tam){
    int i, soma = 0, atual = horas[0].hora, atualM = horas[0].minuto, k = 0;
    *maior = 0;
    while(distintos--){
        for(i = k; horas[i].hora == atual; i++){
            if(horas[i].minuto == atualM){
                soma++;
            }
            else{
                if(soma > maior){
                    *maior = soma;
                    soma = 0;
                }
            }
        }
        if(soma > *maior){*maior = soma;}
        soma = 0;
        atual = horas[i].hora;
        atualM = horas[i].minuto;
        k = i;
    }
 
}
 
int main(){
    int casos, pessoas, i, num, distintos = 1, maior;
    scanf("%d", &casos);
 
    while(casos--){
        scanf("%d", &pessoas);
        Tempo horas[pessoas];
        for(i = 0; i < pessoas; i++){
            scanf("%d %d", &horas[i].hora, &horas[i].minuto);
        }
 
        ordena(&horas, pessoas);
 
        num = horas[0].hora;
        for(i = 0; i < pessoas; i++){
            if(horas[i].hora != num){
                distintos++;
                num = horas[i].hora;
            }
        }
 
        ordenaMinuto(&horas, pessoas, distintos);
        somaMinuto(&horas, distintos, &maior, pessoas);
 
        printf("%d\n", maior);
 
        distintos = 1;
    }
 
}