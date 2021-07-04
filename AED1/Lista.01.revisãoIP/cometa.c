#include<stdio.h>
#include<stdlib.h>

int conta_ano(int ano){
    // no calendário comum 1988 foi o primeiro ano bissexto após 1986.
    // ano solar tem exatamente 365 dias
    // 76 anos (27.740 dias) para cada passagem, marco de pssgm (1986)
    // a cada 1.460 anos o cometa reduz 1 ano de passagem, aproximadamente

int base = 1986, contador = 0;

    if(ano >= base){
while (base){
base = base + 76;
contador++;

// a cada 19.2 ciclos de 76 anos, se passam 1.460 dias o contador conta cada ciclo

if(base > ano && contador < 20){
    return(base);
}else if(base > ano && contador >= 20){
    int referencia = 3446;
    contador = 0;
while (base >= referencia){
contador++;
referencia = referencia + 1541;
}
return(base+contador);
}
}

    }else{
        while (ano < base)
        {
            base = base - 76;
        }
        if(base <= 526)
        {
            base = base +75;
            return(base);
        }
        base = base +76;
        return(base);
    }

}


int main(){

int ano_atual, data;

// printf("entre com o ano atual: ");
do {
    scanf("%d",&ano_atual);
}while(ano_atual <= 0 || ano_atual > 100000);

data = conta_ano(ano_atual);

printf("%d",data);

return 0;
}