#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct data Data;

struct data
{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};

// outubro de de 1582, não teve dos dias 5 a 14.
// lembrar de implementar anos bissextos.

//-----------------------***-----------------------------//

//implentando as funcoes

Data * criaData(unsigned int dia, unsigned int mes, unsigned int ano);
// cria, de maneira dinâmica, uma data a partir dos valores para dia, mes e ano.

Data * copiaData(Data d);
// Cria uma cópia de data d, retornando-a.

void liberaData(Data * d);
// Destroi a data indicada d.

Data * somaDiasData(Data d, unsigned int dias);
//retorna uma data que eh 'dias' posteriores a data d.

Data * subtrairDiasData(Data d, unsigned int dias);
//retorna uma data que eh 'dias' anteriores a data d.

void atribuirData(Data * d, unsigned int dia, unsigned int mes, unsigned int ano);
// atribui a data d, a data dia/mes/ano especificada. Se nao for possivel, retorne d igual a NULL.

unsigned int obtemDiaData(Data d);
//retorna a componente dia da data d.

unsigned int obtemMesData(Data d);
//retorna a componente mes da data d.

unsigned int obtemAnoData(Data d);
// retorna a componente ano da data d.

unsigned int bissextoData(Data d);
//retorna true se a data pertence a um ano bissexto.Do contrario false.

int comparaData(Data d1, Data d2);
// retorna MENOR se d1<d2; IGUAL se d1=d2; MAIOR se d1>d2.

unsigned int numeroDiasDatas(Data d1, Data d2);
// retorna o numero de dias que existe entre as datas d1 e d2.
//se d1=d2, retorna 0. Do contrario sera um numero positivo (modulo).

unsigned int numeroMesesDatas(Data d1, Data d2);
//se d1=d2, retorna 0. Do contrario sera um numero positivo (modulo).

unsigned int numeroAnosDatas(Data d1, Data d2);
//se d1=d2, retorna 0. Do contrario sera um numero positivo (modulo).

unsigned int obtemDiaSemanaData(Data d);
//retorna o dia da semana correspondente a data d.
// domingo = 1, segunda-feira = 2, ... , sabado = 7.

char * imprimeData(Data d, char * formato);
// retorna uma string com a data "formatada" de acordo com o especificado em fomrato.
// formato = "ddmmaaaa" ---> 26/12/1997.
// formato = "aaaammdd" ---> 1997/12/26.
// "aaaa"
// "mm"
// "dd"
// "ddmm"



