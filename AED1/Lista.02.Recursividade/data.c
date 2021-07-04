//===================================================================
// Arquivo.h
//===================================================================

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>


#define MENOR -1
#define MAIOR 1
#define IGUAL 0

#define TRUE 1
#define FALSE 0


typedef struct data Data;

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


//====================================================================
// Arquivo .c
//====================================================================
//#include "data.h"



struct data
{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};


//implentando as funcoes
criaDatateste(unsigned int dia,unsigned int mes,unsigned int ano)
{
    Data* p = (Data*) malloc(sizeof(Data));
        if (p != NULL) {
            p->dia = dia;
            p->mes = mes;
            p->ano = ano;
        }

        return (p);
}

unsigned int validaData(unsigned int dia, unsigned int mes, unsigned int ano)
{
        int p;

    if(mes > 12) {
        return(FALSE);
    }

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if(dia >30) {
            return(FALSE);
        }
    }else if(mes == 2) {
        Data* x = criaDatateste(dia,mes,ano);
        p = bissextoData(*x);
        liberaData(&x);

        if(p == TRUE && dia > 29) {
            return(FALSE);
        }else if( p == FALSE  && dia > 28) {
            return(FALSE);
        }
    }else {
        if(dia > 31) {
            return(FALSE);
        }
    }

    if(ano == 1582 && mes == 10) {
        if(dia > 4 && dia < 15) {
            return(FALSE);
        }
    }

    return(TRUE);
}


Data * criaData(unsigned int dia, unsigned int mes, unsigned int ano)
{
    int x = validaData(dia, mes, ano);
    if(ano < 1900 || ano > 2200)
    {
        return(NULL);
    }

    if(x == FALSE) {
        return (NULL);
    }else {
        Data* p = (Data*) malloc(sizeof(Data));
        if (p != NULL) {
            p->dia = dia;
            p->mes = mes;
            p->ano = ano;
        }

        return (p);
    }
    
}

Data * copiaData(Data d)
{
    Data* p = (Data*) malloc(sizeof(Data));
    if(p != NULL) {
        p->dia = d.dia; 
        p->mes = d.mes;
        p->ano = d.ano;
    }

    return(p);
}

void liberaData(Data * d)
{
    if(d != NULL) {
        free(d);
    }
}

Data * somaDiasData(Data d, unsigned int dias)
{
    unsigned int x;

    while(dias--) {

        if(d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11) {
            if(d.dia == 30) {
                d.dia = 1;
                d.mes++;
            }else {
                d.dia++;
            }

        }else if(d.mes == 2) {
            x = bissextoData(d);

            if(x) {
                if(d.dia == 29) {
                d.dia = 1;
                d.mes++;
                }else {
                    d.dia++;
                }
            }else {
                if(d.dia == 28) {
                d.dia = 1;
                d.mes++;
                }else {
                    d.dia++;
                }
            }
        }else {
            if(d.dia == 31) {
                d.dia = 1;
                d.mes++;
                if(d.mes > 12) {
                    d.mes = 1;
                    d.ano++;
                }
            }else {
                d.dia++;
            }
        }
    }
    
    
    Data* p = copiaData(d);

    return (p);
}

Data * subtrairDiasData(Data d, unsigned int dias)
{
    unsigned int x;

    while(dias--) {
        if(d.dia == 1) {
            d.mes--;

            if(d.mes == 0) {
                d.mes = 12;
                d.ano--;
            }

            if(d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11) {
                d.dia = 30;
            }else if(d.mes == 2) {
                x = bissextoData(d);
                if(x == TRUE) {
                    d.dia = 29;
                }else {
                    d.dia = 28;
                }
            }else {
                d.dia = 31;
            }
        }else {
            d.dia --;
        }
    }

    Data* p = copiaData(d);

    return (p);
}

void atribuirData(Data * d, unsigned int dia, unsigned int mes, unsigned int ano)
{
    int x = validaData(dia, mes, ano);

    if(x == TRUE) {
        if(d != NULL) {
            d->dia = dia;
            d->mes = mes;
            d->ano = ano;
        }
    }else {
        d = NULL;
    }

    if(ano < 1900 || ano > 2200)
    {
        d = NULL;
    }

}

unsigned int obtemDiaData(Data d)
{
    if(d.dia != NULL) {
        unsigned int p = d.dia;
        return (p);
    }

    return (0);
}

unsigned int obtemMesData(Data d)
{
    if(d.mes != NULL) {
        unsigned int p = d.mes;
        return (p);
    }

    return (0);
}

unsigned int obtemAnoData(Data d)
{
    if(d.ano != NULL) {
        unsigned int p = d.ano;
        return (p);
    }

    return (0);
}

unsigned int bissextoData(Data d)
{
    unsigned int p = d.ano%4;

    if(p == 0) {
        p = d.ano%100;
        if(p != 0) {
            return (TRUE);
        }
    }else {
        p = d.ano%400;
        if(p == 0) {
            return (TRUE);
        }
    }
    return (FALSE);
}

int comparaData(Data d1, Data d2)
{
    if(d1.ano > d2.ano) {
        return(MAIOR);
    }

    if(d1.ano < d2.ano) {
        return(MENOR);
    }

    if(d1.ano == d2.ano) {
        if(d1.mes > d2.mes) {
            return(MAIOR);
        }

        if(d1.mes < d2.mes) {
            return(MENOR);
        }

        if(d1.mes == d2.mes) {
            if(d1.dia > d2.dia) {
                return(MAIOR);
            }

            if(d1.dia < d2.dia) {
                return(MENOR);
            }

            if(d1.dia == d2.dia) {
                return (IGUAL);
            }
        }
    }
}


unsigned int numeroDiasDatas(Data d1, Data d2)
{
    unsigned int p, x = 0;
    Data* y;

    p = comparaData(d1,d2);
    if(p == MAIOR) {
        y = copiaData(d2);
        while(p != IGUAL)
        {
            y = somaDiasData(*y, 1);
            x++;
            p = comparaData(d1, *y);
        }
        
    }else if(p == MENOR){
        y = copiaData(d1);
        while(p != IGUAL)
        {
            y = somaDiasData(*y, 1);
            x++;
            p = comparaData(d2, *y);
        }
    }else if(p == IGUAL) {
        return (0);
    }

    return (x);

}

unsigned int numeroMesesDatas(Data d1, Data d2)
{
    int p = (d1.ano * 12) + d1.mes;
    int x = (d2.ano * 12) + d2.mes;

    p = p - x;

    return(abs(p));
}

unsigned int numeroAnosDatas(Data d1, Data d2)
{
    int p = d1.ano - d2.ano;

    return (abs(p));
}

unsigned int obtemDiaSemanaData(Data d)
{
    unsigned int k;

    if(d.mes == 1) {
        d.mes = 13;
        d.ano--;
    }
    if(d.mes == 2) {
        d.mes = 14;
        d.ano--;
    }

    k = d.dia + (2*d.mes) + ((3*(d.mes+1))/5) + d.ano + (d.ano/4) - (d.ano/100) + (d.ano/400) + 2; 

    k %= 7;

    if (k == 0) 
    {
        return (7);
    }else {
        return (k);
    }
    

}

char * imprimeData(Data d, char * formato)
{
    unsigned int x = strlen(formato), i, k = 0;
    char s[11], *p; 

    for(i = 0; i < x; i++)
    {
        if(formato[i] == 'd')
        {
            s[k] = (d.dia/10) + '0';
            s[k + 1] = (d.dia%10) + '0';
            if(i + 2 < x) {
                s[k + 2] = '/';
                k++;
            }
            i ++;
            k += 2;
        }

        if(formato[i] == 'm')
        {
            s[k] = (d.mes/10) + '0';
            s[k +1] = (d.mes%10) + '0';
            if(i + 2 < x) {
                s[k + 2] = '/';
                k++;
            }
            k += 2;
            i ++;
        }

        if(formato[i] == 'a')
        {
            s[k] = (d.ano/1000) + '0';
            s[k + 1] = ((d.ano % 1000)/100) + '0';
            s[k + 2] = ((d.ano%100)/10) + '0';
            s[k + 3] = (d.ano%10) + '0';
            if(i + 4 < x) {
                s[k + 4] = '/';
                k++;
            }
            k += 4;
            i += 3;
        }
    }

    s[k] = '\0';

    p = (char *)malloc(sizeof(char) * strlen(s) + 1);
    strcpy(p, s);
    
    return (p);
}

//====================================================================
// corpo principal
//====================================================================
Data* alldatas[10000] = {NULL};

unsigned int espaco_vago()
{
    unsigned int i;

    for(i = 0; i < 10000; i++)
    {
        if(alldatas[i] == NULL) {
            return (i);
        }
    }
    return(i);
}

void espaco_ocupado()
{
    unsigned int i, g = 0;

    for(i = 0; i < 10000; i++)
    {
        if(alldatas[i] != NULL) {
            printf("%u ", i);
            if(g == 0) {
                g++;
            }
        }
    }

    if(g == 0) 
    {
        printf("Nao a codigos com datas cadastradas!\n");
    }else {
        printf("\nEstes sao os codigos com datas cadastradas!\n");
    }
    system("pause");
}
int main()
{
    unsigned int menu, d, m, a, i, k;

    printf("\n\nBiblioteca de manipulacao de datas\n\n");
    system("pause");

    do
    {
    
        system("cls");
        printf(" Escolha uma das alternativas:\n\n"
        "0. Sair do progama.\n"
        "1. Criar uma data.\n"
        "2. Criar uma copia de uma data.\n"
        "3. Excluir uma data.\n"
        "4. Acrescentar dias a uma data.\n"
        "5. Diminuir dias de uma data.\n"
        "6. Alterar uma data.\n"
        "7. Obter o dia de uma data.\n"
        "8. Obter o mes de uma data.\n"
        "9. Obter o ano de uma data.\n"
        "10. Checar se a data corresponde ha um ano bissexto.\n"
        "11. Comparar duas datas.\n"
        "12. Obter a diferenca de dias entre duas datas.\n"
        "13. Obter a diferenca de meses entre duas datas.\n"
        "14. Obter a diferenca de anos entre duas datas.\n"
        "15. Obter o dia da semana de uma data.\n"
        "16. Imprime a data de acordo com a formatacao.\n"
        "17. Mostra codigos disponiveis para inserir datas!\n"
        "18. Mostrar codigos com datas cadastradas!\n");

        scanf("%u", &menu);

        switch (menu)
        {
        case 0:
            system("cls");
            printf("Encerrando o progama!\n");
            system("pause");
            return (0);
            break;
        
        case 1:
            system("cls");
            printf("Insira em qual codigo, de 0 a 9999, gostaria de guardar a data: ");
            scanf("%u", &i);
            if(alldatas[i] == NULL) 
            {
                printf("Digite respectivamente o dia, mes e ano da data desejada: ");
                scanf("%u %u %u",&d, &m, &a);

                alldatas[i]  = criaData(d, m, a);
                if(alldatas[i] != NULL) {
                    printf("Data criada com sucesso!\nCodigo da data = %u.\n", i);
                }else {
                    printf("Falha ao criar a data!");
                }
            }else {
                printf("Codigo ja ocupado!\n");
            }

            system("pause");
            
            break;
        case 2:
            system("cls");
            printf("Insira em qual codigo, de 0 a 9999, gostaria de guardar a data: ");
            scanf("%u", &i);
            if(alldatas[i] == NULL)
            {
                printf("Insira o codigo da data que deseja criar uma copia: ");
                scanf("%u", &k);

                if(alldatas[k] != NULL) {
                    alldatas[i] = copiaData(*alldatas[k]);
                    if(alldatas[i] != NULL) {
                        printf("Data copiado com sucesso!\nCodigo da nova data = %u.\n", i);
                    }else {
                        printf("Falha ao copiar a data!\n");
                    }
                }else {
                    printf("Codigo indisponivel!\n");
                }
            }else {
                printf("Codigo ja ocupado!\n");
            }

            system("pause");

            break;
        case 3:
            system("cls");
            printf("Insira o codigo da data que deseja excluir: ");
            scanf("%u", &k);

            if(alldatas[k] != NULL) {
                liberaData(alldatas[k]);
                printf("Data excluida com sucesso!\nO codigo %u nao esta mais disponivel!\n",k);
                alldatas[k] = NULL;
            }else {
                printf("Codigo nao ocupado!\n");
            }
            system("pause");
            
            break;
        case 4:
            system("cls");

            printf("Insira em qual codigo, de 0 a 9999, gostaria de guardar a data: ");
            scanf("%u", &i);
            if(alldatas[i] == NULL)
            {
                printf("Insira o codigo da data que deseja incrementar: ");
                scanf("%u", &k);

                if(alldatas[k] != NULL) {
                    printf("Insira a quantidade de dias que deseja incrementar: ");
                    scanf("%u",&d);
                    alldatas[i] = somaDiasData(*alldatas[k], d);
                    if(alldatas != NULL) {
                        printf("Data incrementada com sucesso!\nCodigo da nova data = %u.", i);
                    }else {
                        printf("Falha ao incrementar data!\n");
                    }
                }else {
                    printf("Codigo indisponivel!\n");
                }
            }else {
                printf("Codigo nao ocupado!\n");
            }
            system("pause");
            
            break;
        case 5:
            system("cls");
             
            printf("Insira em qual codigo, de 0 a 9999, gostaria de guardar a data: ");
            scanf("%u", &i);
            if(alldatas[i] == NULL)
            {
                printf("Insira o codigo da data que deseja subtrair: ");
                scanf("%u", &k);

                if(alldatas[k] != NULL) {
                    printf("Insira a quantidade de dias que deseja subtrair: ");
                    scanf("%u",&d);
                    alldatas[i] = subtrairDiasData(*alldatas[k], d);
                    if(alldatas != NULL) {
                        printf("Data subtraida com sucesso!\nCodigo da nova data = %u.", i);
                    }else {
                        printf("Falha ao incrementar data!\n");
                    }
                }else {
                    printf("Codigo indisponivel!\n");
                }
            }else {
                printf("Codigo nao ocupado!\n");
            }
            system("pause");
            
            break;
        case 6:
            system("cls");
             
            printf("Insira o codigo da data que deseja modificar: ");
            scanf("%u",&k);

            if(alldatas[k] != NULL) {
                printf("Digite respectivamente o dia, mes e ano da data desejada: ");
                scanf("%u %u %u",&d, &m, &a);
                atribuirData(alldatas[k], d, m, a);
                if(alldatas[k] != NULL) {
                    printf("Data atribuida com sucesso!\n");
                }else {
                    printf("Falha ao atribuir data!\n");
                }
            }
            system("pause");
            
            break;
        case 7:
            system("cls");

            printf("Insira o codigo da data que deseja obter o dia: ");
            scanf("%u",&k);

            if(alldatas[k] != NULL) {
                i = obtemDiaData(*alldatas[k]);
                printf("A data corrsponde ao dia %u", i);
                
            }else {
                printf("Codigo invalido!\n");
            }
            system("pause");
            
            break;
        case 8:
            system("cls");

            printf("Insira o codigo da data que deseja obter o mes: ");
            scanf("%u",&k);

            if(alldatas[k] != NULL) {
                i = obtemMesData(*alldatas[k]);
                printf("A data corrsponde ao mes %u", i);
                
            }else {
                printf("Codigo invalido!\n");
            }
            system("pause");
            
            break;
        case 9:
            system("cls");

            printf("Insira o codigo da data que deseja obter o ano: ");
            scanf("%u",&k);

            if(alldatas[k] != NULL) {
                i = obtemAnoData(*alldatas[k]);
                printf("A data corrsponde ao ano %u", i);
                
            }else {
                printf("Codigo invalido!\n");
            }
            system("pause");
            
            break;
        case 10:
            system("cls");

            printf("Insira o codigo da data que deseja verificar se possui ano bissexto: ");
            scanf("%u",&k);

            if(alldatas[k] != NULL) {
                i = bissextoData(*alldatas[k]);
                if(i == TRUE) {
                    printf("A data corresponde a um ano bissexto");
                }else {
                    printf("A data nao corresponde a um ano bissexto");
                }
                
            }else {
                printf("Codigo invalido!\n");
            }
            system("pause");
            
            break;
        case 11:
            system("cls");

            printf("Insira o codigo das datas de que deseja comparar, sendo a primeira a referncial: ");
            scanf("%u %u",&i, &k);

            if((alldatas[i] != NULL) && (alldatas[k] != NULL)) {
                i = comparaData(*alldatas[i], *alldatas[k]);

                if(i == MAIOR)
                {
                    printf("A primeira data eh maior que a segunda!\n");
                }
                if(i == MENOR)
                {
                    printf("A primeira data eh menor que a segunda!\n");
                }
                if(i == IGUAL)
                {
                    printf("A primeira data eh igual a segunda!\n");
                }
            }else {
                printf("Um ou ambos os codigos são invalidos!\n");
            }

            system("pause");

            break;
        case 12:
            system("cls");

            printf("Insira o codigo das datas que deseja obter a diferenca de dias: ");
            scanf("%u %u",&i, &k);

            if((alldatas[i] != NULL) && (alldatas[k] != NULL)) {
                i = numeroDiasDatas(*alldatas[i], *alldatas[k]);

                if(i > 1 || i == 0) {
                    printf("A diferenca entre as datas corresponde a %u dias.\n",i);
                }else {
                    printf("A diferenca entre as datas corresponde a %u dia.\n",i);
                }
            }else {
                printf("Um ou ambos os codigos são invalidos!\n");
            }

            system("pause");
            
            break;
        case 13:
            
            system("cls");

            printf("Insira o codigo das datas que deseja obter a diferenca de meses: ");
            scanf("%u %u",&i, &k);

            if((alldatas[i] != NULL) && (alldatas[k] != NULL)) {
                i = numeroMesesDatas(*alldatas[i], *alldatas[k]);

                if(i > 1 || i == 0) {
                    printf("A diferenca entre as datas corresponde a %u meses.\n",i);
                }else {
                    printf("A diferenca entre as datas corresponde a %u mes.\n",i);
                }
            }else {
                printf("Um ou ambos os codigos são invalidos!\n");
            }

            system("pause");
            break;
        case 14:
            system("cls");

            printf("Insira o codigo das datas que deseja obter a diferenca de anos: ");
            scanf("%u %u",&i, &k);

            if((alldatas[i] != NULL) && (alldatas[k] != NULL)) {
                i = numeroAnosDatas(*alldatas[i], *alldatas[k]);

                if(i > 1 || i == 0) {
                    printf("A diferenca entre as datas corresponde a %u anos.\n",i);
                }else {
                    printf("A diferenca entre as datas corresponde a %u ano.\n",i);
                }
            }else {
                printf("Um ou ambos os codigos são invalidos!\n");
            }

            system("pause");
            
            break;
        case 15:
         system("cls");

         printf("Insira o codigo da data que deseja obter o dia da semana: ");
         scanf("%u",&k);

         if(alldatas[k] != NULL) {
            i = obtemDiaSemanaData(*alldatas[k]);

            switch (i)
            {
            case 1:
                printf("A data corresponde a um Domingo!\n");
                break;
            case 2:
                printf("A data corresponde a uma Segunda-Feira!\n");
                break;
            case 3:
                printf("A data corresponde a uma Terca-Feira!\n");
                break;
            case 4:
                printf("A data corresponde a uma Quarta-Feira!\n");
                break;
            case 5:
                printf("A data corresponde a uma Quinta-Feira!\n");
                break;
            case 6:
                printf("A data corresponde a uma Sexta-Feira!\n");
                break;
            case 7:
                printf("A data corresponde a um Sabado!\n");
                break;
            default:
                break;
            }
         }else {
             printf("Codigo ivalido!");
         }
         system("pause");
            
            break;
        case 16:
            system("cls");

            printf("Insira o codigo da data que deseja imprimir: ");
            scanf("%u",&k);

            if(alldatas[k] != NULL) {
                printf("Dentro os formatos possiveis:\n"
                "ddmmaaaa\n"
                "aaaammdd\n"
                "aaaa\n"
                "mm\n"
                "dd\n"
                "ddmm\n"
                "Insira o formato que deseja imprimir: ");

                char s[10], *p = NULL;
                scanf("%s",s);

                p = imprimeData(*alldatas[k], &s);

                if(p != NULL) {
                    printf("%s\n",p);
                }else {
                    printf("Falha ao imprimir data!\n");
                }

            }else {
                printf("Codigo invalido!\n");
            }
            system("pause");
            
            break;
        case 17:
            system("cls");
            k = espaco_vago();
            if(k == 1000) {
                printf("Nao ha espacos disponiveis!\n");
            }else {
                printf("O espaco %u esta disponivel!\n",k);
            }
            system("pause");
            break;
        case 18:
            system("cls");

            espaco_ocupado();
            break;

        default:
            system("cls");
            printf("Voce digitou uma alternativa invalida!\n");
            system("pause");
            break;
        }
    }while(menu != 0);
}
