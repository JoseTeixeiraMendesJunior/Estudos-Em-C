#include<stdio.h>
#include<stdlib.h>

#define SUCESSO 1
#define FALHA -1

typedef struct Nodo* Apontador;

struct Nodo {
    Apontador ant;
    unsigned long int dado;
    Apontador prox;
}nodo;

Apontador prim = NULL;

int InsInicio(unsigned long int dadoPA)
{
    Apontador q;

    q = (Apontador)malloc(sizeof(nodo));
    if(q == NULL) {
        return(FALHA);
    }
    else {
        q->ant = NULL;
        q->dado = dadoPA;
        q->prox = prim;
        prim = q;
        return(SUCESSO);
    }
}

int InsOrdem(unsigned long int dadoPA)
{
    Apontador q, r;

    if(prim == NULL)
    {
        return(InsInicio(dadoPA));
    }
    else {
        if(dadoPA < prim->dado) {
            return(InsInicio(dadoPA));
        }
        else {
            q = (Apontador)malloc(sizeof(nodo));
            if(q == NULL) {
                return(FALHA);
            }
            else {
                q->dado = dadoPA;
                r = prim;

                while((r->dado <= q->dado) && (r->prox != NULL))
                {
                    r = r->prox;
                }

                if(r->prox == NULL) {
                    if(q->dado < r->dado) {
                        q->ant = r->ant;
                        q->prox = r;
                        (*(r->ant)).prox = q;
                        r->ant = q;
                    }
                    else {
                        q->ant = r;
                        q->prox = r->prox;
                        r->prox = q;
                    }
                }
                else {
                    q->ant = r->ant;
                    q->prox = r;
                    (*(r->ant)).prox = q;
                    r->ant = q;
                }
                
                return(SUCESSO);
            }
        }
    }
}

void ImprimeC()
{
    Apontador q = prim;

    while(q->prox != NULL) {
        printf("%lu ",(q->dado));
        q = q->prox;
    }
    printf("%lu",(q->dado));
}

void ImprimeD()
{
    Apontador q = prim;

    while(q->prox != NULL) {
        q = q->prox;
    }
    
    while (q->ant != NULL)
    {
        printf("%lu ",(q->dado));
        q = q->ant;
    }
    printf("%lu",(q->dado));
}

void menor()
{
    unsigned long int aux = 100000;
    Apontador q = prim;

    while(q->prox != NULL) {
        if(q->dado < aux) {
            aux = q->dado;
        }
        q = q->prox;
    }
    if(q->dado < aux) {
            aux = q->dado;
        }
    printf("%lu",aux);   
}

void MAIOR()
{
    unsigned long int aux = 0;
    Apontador q = prim;

    while(q->prox != NULL) {
        if(q->dado > aux) {
            aux = q->dado;
        }
        q = q->prox;
    }
    if(q->dado > aux) {
            aux = q->dado;
        }
    printf("%lu",aux);   
}

int main()
{

    int aux;
    long int dado;
    char result;

    scanf("%ld",&dado);
    while (dado != -1)
    {
        aux = InsOrdem(dado);
        scanf("%ld",&dado);
    }

    //getchar();
    scanf(" %c",&result);

    switch (result)
    {
    case 'C':
        ImprimeC();
        break;
    case 'D':
        ImprimeD();
        break;
    case 'M':
        MAIOR();
        break;
    case 'm':
        menor();
        break;
    default:
        break;
    }
    

    return(0);
}