#include <stdio.h>
#include <stdlib.h>
#include "inteiros.h"

struct elemento
{
    int inteiros;
    struct elemento* prox;
};

typedef struct elemento Elem;

Lista* inicializa()
{
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

int lista_vazia(Lista* li)
{
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    return 0;
}

int lista_cheia(Lista* li)
{
    return 0;
}

int insere_ord(Lista* li, int inteiro)
{
    if(li == NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->inteiros = inteiro;
    if(lista_vazia(li))
    {
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else
    {
        Elem* ant, *atual = *li;
        while(atual != NULL && atual->inteiros < inteiro)
        {
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li)
        {
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}

int remove_ord(Lista* li, int inteiro)
{
    if(li == NULL || inteiro < (*li)->inteiros) return 0;
    Elem *no = *li;

    if(inteiro == (*li)->inteiros)
    {
        *li = no->prox;
        free(no);
        return 1;
    }
    while(no->prox != NULL && no->prox->inteiros < inteiro)
        no = no->prox;
    if(no->prox == NULL || no->prox->inteiros > inteiro)
        return 0;

    Elem *ant = no->prox;
    no->prox = ant->prox;
    free(ant);
    return 1;

}

int get_pos(Lista* li, int pos)
{
    if(li==NULL || pos <= 0) return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos)
    {
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else
    {
        return no->inteiros;
    }
}

int remove_pos(Lista* li, int pos)
{
    if(li == NULL || pos < 0) return 0;
    Elem* ant, *no = *li;
    int i = 1;
    while(no != NULL && i <= pos)
    {
        ant = no;
        no = no->prox;
        i++;
    }
    if(no == NULL) return 0;
    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;

}
