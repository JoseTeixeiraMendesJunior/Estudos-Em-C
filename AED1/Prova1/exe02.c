#include<stdio.h>
#include<stdlib.h>

#define SUCESSO 1
#define FALHA -1

typedef struct Nodo* Apontador;

struct Nodo {
    unsigned int codigo;
    Apontador prox;
}nodo;

Apontador primL1;
Apontador primL2;
Apontador primL3;

int CriaListaVazia(Apontador* p)
{
    (*p) = (Apontador*) NULL;
    return(SUCESSO);
}

int InsInicio(Apontador* p, unsigned int codigoPA)
{
    Apontador q;

    q = (Apontador)malloc(sizeof(nodo));
    if(q == NULL) {
        return(FALHA);
    }
    else {
        q->codigo = codigoPA;
        q->prox = (Apontador) (*p);
        (*p) = q;
        return(SUCESSO);
    }
}

int InsFinal(Apontador* p, unsigned int codigoPA)
{
    Apontador q, x;

    q = (Apontador)malloc(sizeof(nodo));
    if(q == NULL) {
        return(FALHA);
    }
    else {
        q->codigo = codigoPA;
        q->prox = (Apontador) NULL;
        x = (*p);

        while(x->prox != NULL) {
            x = x->prox;
        }

        x->prox = q;
        return(SUCESSO);
    }
}

int InsEmOrdem(Apontador* p, unsigned int codigoPA)
{
    Apontador q, t, x;

    if((*p) == NULL)
    {
        return(InsInicio(p, codigoPA));

    }

    if((*p)->prox == NULL) {

        if(codigoPA < (*p)->codigo) {

            return(InsInicio(p, codigoPA));

        }
        else {
            return(InsFinal(p, codigoPA));
        }
    }

    if(codigoPA < (*p)->codigo) {

        return(InsInicio(p, codigoPA));
    
    }
    else {

        q = (Apontador)malloc(sizeof(nodo));
        if(q == NULL) {
            return(FALHA);
        }

        q->codigo = codigoPA;
        x = (*p);

        while((x->codigo < codigoPA) && (x->prox != NULL)) {
            t = x;
            x = x->prox;
        }

        if(x->codigo <= codigoPA) {
            q->prox = (Apontador) NULL;
            x->prox = q;
        }
        else {
            q->prox = x;
            t->prox = q;
        }
    }

    return(SUCESSO);
}

int RemoveRepeticao(Apontador* p, unsigned int* cont)
{
    Apontador q, x, t;

    x = (*p);
    q = x->prox;
    
    while(x->prox != NULL) {
        if(x->codigo == q->codigo) {
            
            if(q->prox == NULL) {
                x->prox == NULL;
                free(q);
                *cont--;
            }
            else {
                x->prox = q->prox;
                t = q;
                q = q->prox;
                free(t);
                *cont--;

            }
        }
        else {
            x = q;
            q = q->prox;
        }
    }
    return(SUCESSO);
}

void RemInicio(Apontador** p) {
    Apontador x;

    x = (**p);
    (**p) = (**p)->prox;
    free(x);

}

void Diferentes(Apontador* m, Apontador* M) {

    Apontador x, t, q, r, s;
    int flag = 0, contador = 1, contador2, aux;

    q = (*M);
    t = q;

    if((*m) == NULL) {
        flag = FALHA;
    }

    if(flag != FALHA) {
        if((*m)->prox == NULL) {

            while(q->prox != NULL) {

                if(contador == 1) {
                    if((q->codigo) == ((*m)->codigo)) {
                    
                    RemInicio(&M);
                    flag = FALHA;
                    break;
                    }
                    else {
                        q = q->prox;
                    }
                }
                else {
                    if((q->codigo) == ((*m)->codigo)) {
                        t->prox = q->prox;
                        x = q;
                        q = q->prox;
                        free(x);
                        flag = FALHA;
                        break;
                    }
                    else {
                        t = q;
                        q = q->prox;
                    }
                }
                contador ++;
            }
            if((q->codigo) == ((*m)->codigo)) {
                t->prox = NULL;
                free(q);
                flag = FALHA;
            }
        }
        else {
            r = (*m);
            s = r;

            while(r->prox != NULL) {

                contador2 = 1;
                q = (*M);
                t = q;
                
                while(q->prox != NULL) {
                    
                    if((r->codigo) == (q->codigo)) {
                        if(contador == 1) {
                            RemInicio(&m);
                            r = (*m);
                            s = r;

                            contador--;

                            if(contador2 == 1) {

                                RemInicio(&M);
                                q = (*M);
                                t = q;

                                contador2--;
                            }
                            else {

                                x = q;
                                t->prox = q->prox;
                                q = q->prox;
                                free(x);
                            }
                            break;
                        }
                        else if(contador2 = 1) {

                            RemInicio(*M);
                            q = (*M);
                            t = q;

                            contador2--;

                            x = r;
                            s->prox = r->prox;
                            r = r->prox;
                            free(x);
                            break;
                        }
                        else {
                            x = q;
                            t->prox = q->prox;
                            q = q->prox;
                            free(x);

                            x = r;
                            s->prox = r->prox;
                            r = r->prox;
                            free(x);
                            break;
                        }
                    }
                    else {
                        t = q;
                        q = q->prox;
                    }
                    contador2++;
                }
                if((r->codigo) == (q->codigo)) {
                    if(contador == 1) {

                        RemInicio(&m);
                        r = (*m);
                        s = r;
                        contador--;
                    }
                    else {

                        x = r;
                        s->prox = r->prox;
                        r = r->prox;
                        free(x);
                    }

                    t->prox = NULL;
                    free(q);
                }

                s = r;
                r = r->prox;

                contador++;
            }
            q = (*M);
            t = q;
            contador2 = 1;

            while(q->prox != NULL) {

                if((r->codigo) == (q->codigo)) {
                    
                    if(contador2 == 1) {
                        RemInicio(&M);
                        
                    }
                    else {

                        x = q;
                        t->prox = q->prox;
                        q = q->prox;
                        free(x);
                    }

                    s->prox = NULL;
                    free(r);
                    break;
                }
                contador2++;
            }

            if((r->codigo) == (q->codigo)) {
                
                t->prox = NULL;
                s->prox = NULL;
                free(q);
                free(r);
            }
            
        }

        contador = 0;

        if(((*m) == NULL) || ((*M) ==  NULL)) {
            flag = FALHA;
        }
    }

    printf("diferentes ");

    if(flag == FALHA) {
        q = (*M);
        r = (*m);
        
        if((*M) == NULL) {
            while(r != NULL) {
                printf("%u ",r->codigo);
                r = r->prox;
            }
            printf("%u\n",r->codigo);
        }
        else {
            while(q->prox != NULL) {
                printf("%u ",q->codigo);
                q = q->prox;
            }
            printf("%u\n",q->codigo);
        }
    }
    else {
        contador = CriaListaVazia(&primL3);

        while(q->prox != NULL) {
            aux = InsEmOrdem(&primL3, q->codigo);
            q = q->prox;
        }
        aux = InsEmOrdem(&primL3, q->codigo);

        while(r->prox != NULL) {
            aux = InsEmOrdem(&primL3, r->codigo);
            r = r->prox;
        }
        aux= InsEmOrdem(&primL3, r->codigo);

         t = primL3;

        while(t->prox != NULL) {
            printf("%u ",t->codigo);
            t = t->prox;
        }
        printf("%u\n",t->prox);

    }

}

int TesteIguais(Apontador p, Apontador x) {

    while(p->prox != NULL) {

        if((p->codigo) != (x->codigo)) {
            return(FALHA);
        }
        else {
            p = p->prox;
            x = x->prox;
        }
    }
    if((p->codigo) != (x->codigo)) {
        return(FALHA);
    }

    return(SUCESSO);
}


int main()
{
    unsigned int cont1 = 0, cont2 = 0;
    int aux, codigo;

    aux = CriaListaVazia(&primL1);
    aux = CriaListaVazia(&primL2);
    
    while(cont1 < 2000) {
        scanf("%d",&codigo);

        if(codigo == -1) {
            break;
        }

        aux = InsEmOrdem(&primL1, codigo);

        if(aux == SUCESSO) {
            cont1++;
        }
    }

    while(cont2 < 2000) {
        scanf("%d",&codigo);

        if(codigo == -1) {
            break;
        }

        aux = InsEmOrdem(&primL2, codigo);
        
        if(aux == SUCESSO) {
            cont2++;
        }
    }

    if(cont1 > 1) {
        aux = RemoveRepeticao(&primL1, &cont1);
    }
     if(cont2 > 1) {
         aux = RemoveRepeticao(&primL2, &cont2);
     }

     if(cont1 == cont2) {
         aux = TesteIguais(primL1, primL2);

         if(aux == SUCESSO) {
             printf("iguas %u\n",cont2);
         }
         else {
             Diferentes(&primL1, &primL2);
         }
     }
     else {
         if(cont1 > cont2) {
             Diferentes(&primL2, &primL1);
         }
         else {
             Diferentes(&primL1, &primL2);
         }

     }


    return(0);
}