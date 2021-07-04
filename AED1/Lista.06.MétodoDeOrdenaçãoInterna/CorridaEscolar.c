#include <stdio.h>
 
typedef struct torneio{
    int tipo;
    int soma;
    int vetor[6];
} Torneio;
 
 
int main(){
    int n, m, i, j = 0, tipo = 1, tempo = 10000, k, indice;
    scanf("%d %d", &n, &m);
    Torneio turma[n];
 
    for(k = 0; k < n; k++){
        scanf("%d", &turma[j].tipo);
        turma[j].soma = 0;
        for(i = 0; i < m; i++){
            scanf("%d", &turma[j].vetor[i]);
            turma[j].soma += turma[j].vetor[i];
        }
        j++;
    }
 
    for(k = 0; k < 2; k++){
        for(i = 0; i < n; i++){
            if(turma[i].tipo == tipo){
                if(turma[i].soma < tempo){
                    tempo = turma[i].soma;
                    indice = i;
                }
            }
        }
        printf("%d ", indice+1);
        tipo = 2;
        tempo = 10000;
    }
}