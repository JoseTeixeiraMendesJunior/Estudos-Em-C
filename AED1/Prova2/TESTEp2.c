#include<stdio.h>
#include<stdlib.h>

#define SUCESSO 1
#define FALHA -1

typedef struct Celula* ApontadorCelula;

typedef struct Descritor* ApontadorDescritor;

typedef struct Celula
{
    ApontadorCelula ant;
    int dado;
    ApontadorCelula prox;
}Celula;

typedef struct Descritor
{
    ApontadorCelula prim;
    int soma;
    ApontadorCelula ult;
}Descritor;

// ApontadorDescritor Fixo = NULL;

int PrimerioElemento(int d, ApontadorDescritor* Fixo)
{
    ApontadorCelula q;
    
    (*Fixo) = (ApontadorDescritor) malloc(sizeof(struct Descritor));
    if((*Fixo) == NULL) {
        return(FALHA);
    }
    else {
        (*Fixo)->prim = (ApontadorCelula) NULL;
        (*Fixo)->ult = (ApontadorCelula) NULL;
        (*Fixo)->soma = 0;
    }

    q = (ApontadorCelula) malloc(sizeof(struct Celula));
    if(q == NULL) {
        return(FALHA);
    }
    else {
        q->dado = d;
        q->ant = (ApontadorCelula) NULL;
        q->prox = (ApontadorCelula) NULL;

        (*Fixo)->prim = q;
        (*Fixo)->soma = q->dado;
        (*Fixo)->ult = q; 

        return(SUCESSO);
    }
}

int InsFinal(int d, ApontadorDescritor* Fixo)
{
    ApontadorCelula q;
    int aux;

    q = (ApontadorCelula) malloc(sizeof(struct Celula));
    if(q == NULL) {
        return(FALHA);
    }
    else {
        q->dado = d;
        q->prox = (ApontadorCelula) NULL;
        q->ant = (*Fixo)->ult;

        (*Fixo)->ult)->prox = q;
        (*Fixo)->ult = q;
        
        aux = ValidRepet(d);
        if(aux == SUCESSO) {
            (*Fixo)->soma += d;
        }

        return(SUCESSO);

    }

}

int ValidRepet(int d)
{
    ApontadorCelula q = Fixo->prim;

     while(q->prox != NULL)
    {
        if(q->dado == d)
        {
            return(FALHA);
        }
        q = q->prox;
    }

    if(q->dado == d)
    {
        return(FALHA);
    }
    else {
        return(SUCESSO);
    }
}

int main()
{
    int N, d, aux, i;
    ApontadorDescritor Fixo;

    scanf("%d",&N);

    for(i = 0; i < N; i++)
    {
        scanf("%d",&d);

        if(i != 0) {
            aux = InsFinal(d, &Fixo);
        }
        else {
            aux = PrimerioElemento(d, &Fixo);
        }
    }

    printf("%d\n",Fixo->soma);
    
    return(0);
}