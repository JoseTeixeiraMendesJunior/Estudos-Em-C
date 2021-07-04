#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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


Data * criaData(unsigned int dia, unsigned int mes, unsigned int ano)
{
    Data* p = (Data*) malloc(sizeof(Data));
	if (p != NULL) {
		p->dia = dia;
		p->mes = mes;
		p->ano = ano;
	}

    return (p);
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
                if(x) {
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
    int p;

    if(mes > 12) {
        d = NULL;
    }

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if(dia >30) {
            d = NULL;
        }
    }else if(mes == 2) {
        Data* x = criaData(dia,mes,ano);
        p = bissextoData(*x);
        liberaData(&x);

        if(p == 1 && dia > 29) {
            d = NULL;
        }else if( p == 0  && dia > 28) {
            d = NULL;
        }
    }else {
        if(dia > 31) {
            d = NULL;
        }
    }

    if(ano == 1582 && mes == 10) {
        if(dia > 4 && dia < 15) {
            d = NULL;
        }
    }

    if(d != NULL) {
        d->dia = dia;
        d->mes = mes;
        d->ano = ano;
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
            return (1);
        }
    }else {
        p = d.ano%400;
        if(p == 0) {
            return (1);
        }
    }
    return (0);
}

int comparaData(Data d1, Data d2)
{
    if(d1.ano > d2.ano) {
        return(1);
    }

    if(d1.ano < d2.ano) {
        return(-1);
    }

    if(d1.ano == d2.ano) {
        if(d1.mes > d2.mes) {
            return(1);
        }

        if(d1.mes < d2.mes) {
            return(-1);
        }

        if(d1.mes == d2.mes) {
            if(d1.dia > d2.dia) {
                return(1);
            }

            if(d1.dia < d2.dia) {
                return(-1);
            }

            if(d1.dia == d2.dia) {
                return (0);
            }
        }
    }
}

// funcao auxiliar para numeroDiasDatas, nao  pode ser chamada pela biblioteca.
unsigned int auxNumeroDiasDatas(Data d1, Data d2)
{
    int a, b, aux;

    a = numeroAnosDatas(d1, d2);
    aux = a;
    a *= 365;

    b = bissextoData(d1);
        switch (d1.mes)
        {
        case 1:
            a += 31;
            a -= (31-d1.dia);
            break;
        case 2:
            a += 59;
            if(b == 1) {
                a++;
                a -= (29-d1.dia);
            }else{
                a -= (28-d1.dia);
            }
            break;
        case 3:
            a += 90;
            a -= (31-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 4:
            a += 120;
            a -= (30-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 5:
            a += 151;
            a -= (31-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 6:
            a += 181;
            a -= (30-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 7:
            a += 212;
            a -= (31-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 8:
            a += 243;
            a -= (31-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 9:
            a += 273;
            a -= (30-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 10:
            a += 304;
            a -= (31-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 11:
            a += 334;
            a -= (30-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        case 12:
            a += 365;
            a -= (31-d1.dia);
            if(b == 1) {
                a++;
            }
            break;
        
        default:
            break;
        }

        b = bissextoData(d2);
        switch (d2.mes)
        {
        case 1:
            a -= 31;
            a += (31-d2.dia);
            break;
        case 2:
            a -= 59;
            if(b == 1) {
                a--;
                a += (29-d2.dia);
            }else{
                a += (28-d2.dia);
            }
            break;
        case 3:
            a -= 90;
            a += (31-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 4:
            a -= 120;
            a += (30-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 5:
            a -= 151;
            a += (31-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 6:
            a -= 181;
            a += (30-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 7:
            a -= 212;
            a += (31-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 8:
            a -= 243;
            a += (31-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 9:
            a -= 273;
            a += (30-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 10:
            a -= 304;
            a += (31-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 11:
            a -= 334;
            a += (30-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        case 12:
            a -= 365;
            a += (31-d2.dia);
            if(b == 1) {
                a--;
            }
            break;
        
        default:
            break;
        }
        
        aux --;
        do{
            if(b == 1) {
                aux /=4;
            }else {
                d2.ano++;
                b = bissextoData(d2);
                aux--;
            }
        }while(b == 0);

        a+= aux;

        return (a);

    
}

unsigned int numeroDiasDatas(Data d1, Data d2)
{
    unsigned int p;

    if(d1.ano > d2.ano) {
        p = auxNumeroDiasDatas(d1, d2);
    }else {
        p = auxNumeroDiasDatas(d2, d1);
    }

    return (p);

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
    unsigned int x = strlen(*formato), i;

    if(x == 8) {
        // add duas / em cada
        if(formato[0] == 'd'){

        }else {

        }
    }

    if(x == 4) {
        if(formato[0] == 'a') {
            
        }else {
            // add uma /

        }
    }

    if(x == 2) {
        if(formato[0] == 'd') {

        }else {
            
        }

    }
}
// retorna uma string com a data "formatada" de acordo com o especificado em fomrato.
// formato = "ddmmaaaa" ---> 26/12/1997.
// formato = "aaaammdd" ---> 1997/12/26.
// "aaaa"
// "mm"
// "dd"
// "ddmm"