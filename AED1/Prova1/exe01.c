#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define SUCESSO 1
#define FALHA -1

typedef struct Nodo* Apontador;

struct Nodo {
    unsigned int chave;
    float dado;
    Apontador prox;
}nodo;

Apontador prim = NULL;

int InsInicio(unsigned int chavePA, float dadoPA)
{
    Apontador q;

    q = (Apontador)malloc(sizeof(nodo));
    if(q == NULL) {
        return(FALHA);
    }
    else {
        q->chave = chavePA;
        q->dado = dadoPA;
        q->prox = prim;
        prim = q;
        return(SUCESSO);
    }
}

int TamanhoLista()
{
    int tamanho = 0;

    if(prim != NULL)
    {
        Apontador p = prim;
        tamanho++;

        while(p->prox != NULL)
        {
            p = p->prox;
            tamanho++;
    }
    }
    
    return(tamanho);
}

int InsMeio(unsigned int chavePA, float dadoPA, unsigned int x)
{
    Apontador q, p = prim;

    q = (Apontador)malloc(sizeof(nodo));
    if(q == NULL) {
        return(FALHA);
    }
    else {
        x--;
        while(x)
        {
            p = p->prox;
            x--;
        }
        q->chave = chavePA;
        q->dado = dadoPA;
        q->prox = p->prox;
        p->prox = q;
        return(SUCESSO);
    }
}

int RemPorChave(unsigned int chavePA)
{
    Apontador q, p;

    if(prim == NULL)
    {
        return(FALHA);
    }
    
    q = prim;
    p = prim;

    if(q->prox == NULL) 
    {
        if(q->chave == chavePA) {
            return(RemovInc());
        }
        else {
            return(FALHA);
        }
    }
    else {
        if(q->chave == chavePA) {
            return(RemovInc());
        }
        else {
            while((q->prox != NULL) && (q->chave != chavePA))
            { 
                p = q;
                q = q->prox;
            }
            if(q->chave == chavePA) {
                p->prox = q->prox;
                free(q);
                return(SUCESSO);
            }
            else {
                return(FALHA);
            }
        }
    }
}

int RemovInc()
{
    Apontador q;

    if(prim == NULL)
    {
        return(FALHA);
    }
    else {
        q = prim;
        prim = prim->prox;
        free(q);
        return(SUCESSO);
    }
}

int ValidChave(unsigned int chavePA)
{
    Apontador q = prim;

    if(prim == NULL)
    {
        return(SUCESSO);
    }

    while(q->prox != NULL)
    {
        if(q->chave == chavePA)
        {
            return(FALHA);
        }
        q = q->prox;
    }

    if(q->chave == chavePA)
    {
        return(FALHA);
    }
    else {
        return(SUCESSO);
    }
}

void ImprimeLista()
{
    if(prim == NULL) {
        printf("A Lista nao possui elementos!\n");
        system("pause");
    }
    else {
        Apontador q = prim;

        while(q->prox != NULL) {
            printf("chave = %u / dado = %.2f\n",(q->chave),(q->dado));
            q = q->prox;
        }
        printf("chave = %u / dado = %.2f\n",(q->chave),(q->dado));
        system("pause");
    }
    
}

int DesalocaLista()
{
    Apontador q = prim, p = prim;

    if(prim == NULL)
    {
        return(FALHA);
    }

    if(q->prox == NULL)
    {
        free(q);
        return(SUCESSO);
    }
    else {
        while(q->prox != NULL)
        {
            p = q;
            q = q ->prox;
            free(p);
        }

        free(q);
        return(SUCESSO);
    }


}


int main()
{
    unsigned int menu, tam, chave;
    int aux;
    float dado;

    printf("\n\nBem vindo ao menu de manipulacao de Lista Linear!\n\n");
    system("pause");

    do {
        system("cls");
        printf("Escolha umas das opcoes abaixo:\n"
        "0. Para sair do progama\n"
        "1. Para Inserir um Nodo na Lista Linear\n"
        "2. Para Exluir um Nodo da Lista Linear\n"
        "3. Imprimir a Lista Linear\n");

        scanf("%u",&menu);

        switch (menu)
        {
        case 0:
            system("cls");
            aux = DesalocaLista();
            printf("Encerrando o progama!\n");
            system("pause");
            return (0);
            break;

        case 1:
            system("cls");
            printf("Entre com os valores de chave e do dado, respectivamente, a serem armazenados: ");
            scanf("%u %f",&chave,&dado);
            
            aux = ValidChave(chave); 
            
            if(aux == SUCESSO) {
                tam = TamanhoLista();
                if(tam < 2) {
                    aux = InsInicio(chave, dado);
                    if(aux == SUCESSO) {
                        printf("\nNodo inserido na Lista com sucesso!\n");
                        system("pause");
                    }
                    else {
                        printf("\nFalha ao inserir o Nodo na Lista!\n");
                        system("pause");
                    }
                }
                else {
                    aux = InsMeio(chave, dado, tam/2);
                    if(aux == SUCESSO) {
                        printf("\nNodo inserido na Lista com sucesso!\n");
                        system("pause");
                    }
                    else {
                        printf("\nFalha ao inserir o Nodo na Lista!\n");
                        system("pause");
                    }
                }
            }
            else {
                printf("\nNumero de chave ja registrado!\n");
                system("pause");
            }
            break;

        case 2:
            system("cls");
            printf("Entre com o valor chave do Nodo que deseja retirar da lista: ");
            scanf("%u",&chave);

            aux = RemPorChave(chave);

            if(aux == SUCESSO) {
                printf("\nNodo com numero de chave %u removido com o sucesso da Lista!\n",chave);
                system("pause");
            }
            else {
                printf("\nFalha ao remover o Nodo com numero de chave %u, chave inexistente!\n",chave);
                system("pause");
            }
            break;

        case 3:
            system("cls");
            printf("Seguem os itens chave e dado de cada item da Lista, em sua ordem de implantacao!\n");
            ImprimeLista();
            break;
            
        default:
            break;
        }
    }while(menu != 0);
}