#include <stdio.h>
#include <stdlib.h>
#include "bebida.h"

int main()
{
    Lista* li;
    struct bebida *b1 = (struct bebida*)malloc(sizeof(struct bebida));
    int n, cont = 0;
    char name[20];

    do
    {
        printf("[1] Inicializar Lista\n");
        printf("[2] Inserir Elemento\n");
        printf("[3] Remover Elemento\n");
        printf("[4] Imprimir Lista\n");
        printf("[5] Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d" , &n);

        switch(n)
        {
        case 1:
            li = inicializa();
            break;
        case 2:
            printf("Digite o nome da bebida: ");
            setbuf(stdin,NULL);
            fgets(b1->nome,20,stdin);
            setbuf(stdin,NULL);
            printf("Digite o volume da bebida: ");
            scanf("%d", &b1->volume);
            printf("Digite o preco: ");
            scanf("%f", &b1->preco);
            if (insere_ord(li,b1) == 1)
            {
                printf("insercao concluida\n\n");
                cont++;
                free(b1);
                break;
            }else
            {
                printf("Falhou\n\n");
                free(b1);
                break;
            }
        case 3:
            printf("Digite o nome da bebida que quer eliminar: ");
            setbuf(stdin,NULL);
            fgets(name,20,stdin);
            if(remove_ord(li,name) == 1)
            {
                printf("remocao concluida\n\n");
                cont--;
                break;
            }else
                printf("Falhou \n\n");
            break;
        case 4:
            if(lista_vazia(li) == 1)
            {
                printf("Lista Vazia\n\n");
                break;
            }
            printf("LISTA\n\n");

            for(int i = 1; i <= cont;i++)
            {
                struct bebida* imprime = (struct bebida*)malloc(sizeof(struct bebida));
                *imprime = get_pos(li,i);

                printf("Bebida %d:\n", i);
                printf("%s", imprime->nome);
                printf("%d ml\n", imprime->volume);
                printf("R$ %f\n", imprime->preco);
                free(imprime);
            }
                break;
        case 5:
            return 1;
            break;

        default:
            printf("opcao Invalida\n\n");
            break;

        }

    }while(n != 5);

    system("pause");
    return 0;
}
