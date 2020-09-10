#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"

int main()
{
    Lista* li;
    struct alunos *al = (struct alunos*)malloc(sizeof(struct alunos));
    int n, cont = 0;
    unsigned int matricula;

    do
    {
        printf("[1] Inicializa Lista\n");
        printf("[2] Insere aluno\n");
        printf("[3] Remove Aluno\n");
        printf("[4] Tamanho da Lista\n");
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
            printf("Digite o nome do aluno: ");
            setbuf(stdin,NULL);
            fgets(al->nome,20,stdin);
            printf("Digite a matricula: ");
            scanf("%d", &al->matricula);
            printf("Digite a media: ");
            scanf("%f", &al->media);
            printf("Digite as faltas: ");
            scanf("%d", &al->faltas);
            if(insere_elem(li,al) != 1)
            {
                printf("FALHOU\n\n");
                break;
            }
            else
            {
                printf("SUCESSO\n\n");
                cont++;
                break;
            }
        case 3:
            printf("Digite a matricula do aluno que deseja remover: ");
            scanf("%d", &matricula);
            if(remove_elem(li,matricula) != 1)
            {
                printf("FALHOU\n\n");
                break;
            }
            else
            {
                printf("SUCESSO\n\n");
                cont--;
                break;
            }
        case 4:
            printf("TAMANHO: %d", size_lista(li));
            printf("\n\n");
            break;
        case 5:
            if(lista_vazia(li) == 1)
            {
                printf("LISTA VAZIA\n\n");
                break;
            }
            else
            {
                printf("Lista:\n\n");


                for(int i = 1; i <= cont;i++)
                {
                    struct alunos *imprime = (struct alunos*)malloc(sizeof(struct alunos));
                    *imprime = get_pos(li,i);
                    printf("Aluno %d:\n", i);
                    printf("Nome: %s", imprime->nome);
                    printf("Matricula: %d\n", imprime->matricula);
                    printf("Media: %f\n", imprime->media);
                    printf("Faltas: %d\n\n", imprime->faltas);
                    free(imprime);
                }
                break;
            }


        case 6:
            return 1;
            break;
        default:
            printf("opcao invalida, digite novamente\n\n");
            break;
        }
    }while(n != 6);

    system("pause");
    return 0;
}
