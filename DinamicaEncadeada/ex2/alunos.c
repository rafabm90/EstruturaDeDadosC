#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"

struct elemento
{
    struct alunos dados;
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

int size_lista(Lista* li)
{
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li)
{
    return 0;
}

int lista_vazia(Lista* li)
{
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insere_elem(Lista* li,struct alunos* al)
{
    if(li==NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = *al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int remove_elem(Lista* li, int mat)
{
    if(li == NULL) return 0;
    Elem* ant,*no = *li;
    while(no != NULL && no->dados.matricula != mat)
    {
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0;
    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

struct alunos get_pos(Lista* li, int pos)
{
    if(li == NULL || pos <= 0) exit(1);
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos)
    {
        no = no->prox;
        i++;
    }
    if(no == NULL) exit(1);
    else
        return no->dados;
};
