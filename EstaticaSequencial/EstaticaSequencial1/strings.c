#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"


struct lista
{
    int Fim;
    char string[MAX][10]
};


Lista* inicializar_lista()
{
    Lista* lst;
    lst = (Lista*)malloc(sizeof(struct lista));
    if(lst != NULL)
        lst->Fim = 0;
    return lst;
}

void libera_lista(Lista* lst)
{
    free(lst);
}

int lista_cheia(Lista* lst)
{
    if(lst == NULL)
        return -1;
    return (lst->Fim == MAX);
}


int lista_vazia(Lista* lst)
{
    if(lst == NULL)
        return -1;
    return (lst->Fim == 0);
}

int insere_elem(Lista *lst, char str[10])
{
   if(lst == NULL)
        return 0;
    if(lst->Fim == MAX)
        return 0;

    strcpy(lst->string[lst->Fim],str);
    lst->Fim++;

    return 1;
}

int remove_elem(Lista *lst)
{
    if(lst == NULL)
        return 0;
    if(lst->Fim == 0)
        return 0;
    lst->Fim--;
    return 1;
}

char *get_pos(Lista *lst, int i)
{
    if(lst == NULL)
        return 0;
    if(lista_vazia(lst) == 1)
       return 0;
    if(i < lst->Fim)
        return lst->string[i];
}
