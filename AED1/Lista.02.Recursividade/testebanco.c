#include <stdio.h>

typedef struct{
   int q;
   int v;
}din;

int count(din notas[], int indice, int saque){

   if(saque == 0) {return 1;}

   if(saque < 0){return 0;}

   if(indice < 0){return 0;}

   int esq, dir;

   if (notas[indice].q <= 0){
      esq = 0;

   } else {

      /*Para se controlar o número de notas, subtrai-se antes de chamar a função e,
      com o retorno da função, restitui-se o valor ao estado anterior*/
      notas[indice].q--;
      esq = count(notas, indice, saque - notas[indice].v);
      notas[indice].q++;
   }
   dir = count(notas, indice - 1, saque);
   return esq + dir;
}

int main(void){
  int t,x;
  din n[6];
  scanf("%d",&saque);
  for(x=0;x<6;x++) scanf("%d",&n[x].q);
  for(x=0;x<6;x++){
    if(x==0) n[x].v=2;
    else if(x==1) n[x].v=5;
    else if(x==2) n[x].v=10;
    else if(x==3) n[x].v=20;
    else if(x==4) n[x].v=50;
    else if(x==5) n[x].v=100;
  }
  printf("%d\n",count(n, 5, saque));
  return 0;
}