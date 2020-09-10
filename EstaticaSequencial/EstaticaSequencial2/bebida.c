#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bebida.h"

struct lista
{
    int fim;
    struct bebida dados[MAX];
};

Lista* inicializa()
{
    Lista* li;
    li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
        li->fim = 0;
    return li;
}

int lista_cheia(Lista* li)
{
    if(li == NULL) return -1;
    return (li->fim == MAX);
}

int lista_vazia(Lista* li)
{
    if(li == NULL) return -1;
    return (li->fim == 0);
}

int insere_ord(Lista* li, struct bebida* b1)
{
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int k, i = 0;
    if(strcmp(li->dados[i].nome,b1->nome) == 0)
    {
        while(i<li->fim && li->dados[i].volume < b1->volume)
            i++;
    }else
    {
        while(i<li->fim && strcmp(li->dados[i].nome,b1->nome) < 0)
        i++;
    }

    for(k = li->fim-1;k >= i;k--)
        li->dados[k+1] = li->dados[k];
    li->dados[i]= *b1;
    li->fim++;
    return 1;
}

int remove_ord(Lista* li, char* name)
{
    if(li == NULL) return 0;
    if(li->fim == 0) return 0;
    int k, i = 0;
    while(i < li->fim && strcmp(li->dados[i].nome,name) != 0)
        i++;
    if(i == li->fim) return 0;
    for(k = i;k < li->fim-1;k++)
        li->dados[k] = li->dados[k+1];
    li->fim--;
    return 1;
}

struct bebida get_pos(Lista* li, int pos)
{
    if(li == NULL || pos <= 0 || pos > li->fim)
        exit(1);
     return li->dados[pos-1];
};

