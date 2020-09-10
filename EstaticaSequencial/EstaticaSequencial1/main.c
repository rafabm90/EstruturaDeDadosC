#include <stdio.h>
#include <stdlib.h>
#include "strings.h"


int main()
{
    Lista* lst;
    int cont = 0,n;
    char str[10],str1[10];

    do
        {
            printf("[1] Inicializar Lista\n");
            printf("[2] Inserir elemento\n");
            printf("[3] Remover elemento\n");
            printf("[4] Imrpimir lista\n");
            printf("[5] Libera lista\n");
            printf("[6] Sair\n\n");

            printf("Digite a opcao desejada: ");
            scanf("%d", &n);

            switch(n)
            {
                case 1:
                    lst = inicializar_lista();
                    break;

                case 2:
                    printf("Digite o elemento que deseja inserir: ");
                    setbuf(stdin,NULL);
                    fgets(str,10,stdin);
                    setbuf(stdin,NULL);
                    if(insere_elem(lst, str) == 1)
                    {
                        printf("Insercao Concluida\n");
                        cont++;
                        break;
                    }
                    else
                        printf("Falha na insercao\n");
                    break;

                case 3:
                    if(remove_elem(lst) == 1)
                    {
                        printf("Remocao Concluida\n\n");
                        cont--;
                        break;
                    }

                    else
                        printf("Falha na remocao\n\n");
                    break;

                case 4:
                    if(lista_vazia(lst) == 1)
                    {
                         printf("LISTA VAZIA\n\n");
                         break;
                    }else
                    {
                        printf("Lista\n\n");
                        for(int i = 0; i < cont;i++)
                        {
                            printf("%s\n", get_pos(lst,i));
                        }
                        break;
                    }
                case 5:
                    libera_lista(lst);
                    break;
                case 6:
                    return 1;
                    break;

                default:
                    printf("Opcao Invalida, Digite Novamente\n\n");
                    break;
            }



        }while(n != 6);

    return 0;

}
