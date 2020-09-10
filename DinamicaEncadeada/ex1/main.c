#include <stdio.h>
#include <stdlib.h>
#include "inteiros.h"

int main()
{
    Lista* li;
    int n,cont = 0, inteiro, remove,pos;

    do
    {
        printf("[1] Inicializar Lista\n");
        printf("[2] Inserir Inteiro\n");
        printf("[3] Remove Ord\n");
        printf("[4] Remove Pos\n");
        printf("[5] Imprime Lista\n");
        printf("[6] Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            li = inicializa();
            break;
        case 2:
            printf("Digite o inteiro que deseja inserir: ");
            scanf("%d", &inteiro);
            if(insere_ord(li,inteiro) != 1)
            {
                printf("Falhou\n\n");
                break;
            }
            else
            {
                printf("Sucesso\n\n");
                cont++;
                break;
            }
        case 3:
            printf("Digite o inteiro que deseja remover: ");
            scanf("%d", &remove);
            if(remove_ord(li,remove) != 1)
            {
                printf("Falhou\n\n");
                break;
            }
            else
            {
                printf("Sucesso\n\n");
                cont--;
                break;
            }
        case 4:
            printf("Digite a posicao que deseja remover: ");
            scanf("%d", &pos);
            if(remove_pos(li,pos) != 1)
            {
                printf("Falhou\n\n");
                break;
            }
            else
            {
                printf("Sucesso\n\n");
                cont--;
                break;
            }
        case 5:
            if(lista_vazia(li) == 1)
            {
                printf("LISTA VAZIA\n\n");
                break;
            }
            else
            {
                printf("Lista:\n");
                for(int i = 1;i <= cont;i++)
                {
                    printf("%d\n\n", get_pos(li,i));
                }
            }
            break;

        case 6:
            system("pause");
            return 1;
        default:
            printf("Opcao Invalida, digite novamente!\n\n");
            break;
        }
    }while(n != 6);

    system("pause");
    return 0;
}
