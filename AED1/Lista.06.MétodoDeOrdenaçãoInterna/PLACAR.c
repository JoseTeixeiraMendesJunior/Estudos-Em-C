#include <stdio.h>
#include <string.h>
 
typedef struct Turma{
    char nome[100];
    int nota;
} turma;
 
 
void ordenaNota(turma *aluno, int tam){
    int i, j;
    turma aux;
    for(i = 0;  i < tam; i++){
        for(j = i+1; j < tam; j++){
            if(aluno[i].nota < aluno[j].nota){
                aux = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = aux;
            }
        }
    }
}
 
void ordenaNome(turma *aluno, int tam, int distintos){
    int num = aluno[0].nota, i, j, k = 0;
    turma aux;
    while(distintos--){
        for(i = k; aluno[i].nota == num; i++){
            for(j = i+1; aluno[j].nota == num; j++){
                if(strcmp(aluno[j].nome, aluno[i].nome) < 0){
                    aux = aluno[i];
                    aluno[i] = aluno[j];
                    aluno[j] = aux;
                }
            }
        }
        k = i;
        num = aluno[i].nota;
    }
}
 
int main(){
    int casos, i, distintos = 1, num;
    scanf("%d", &casos);
    turma aluno[casos];
    for(i = 0; i < casos; i++){
        scanf("%s", aluno[i].nome);
        scanf("%d", &aluno[i].nota);
    }
 
    ordenaNota(&aluno, casos);
    
    num = aluno[0].nota;
    for(i = 0; i < casos; i++){
        if(aluno[i].nota != num){
            distintos++;
            num = aluno[i].nota;
        }
    }
    
    ordenaNome(&aluno, casos, distintos);
    for(i = 0; i < casos - 1; i++){
        printf("%s %d\n", aluno[i].nome, aluno[i].nota);
    }
    printf("%s %d #reprovado(a)", aluno[casos-1].nome, aluno[casos-1].nota);   
}