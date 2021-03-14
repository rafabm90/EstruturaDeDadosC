/*

  by: Rafael Borges Morais
  
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int N, c,d,u;
    char unidade[10][100] = {"","um" , "dois" , "tres", "quatro" , "cinco" , "seis" , "sete" , "oito" , "nove"};
    char dezena[10][100] = {"","dez","vinte","trinta","quarenta", "cinquenta", "sessenta", "setenta","oitenta", "noventa"};
    char centena[10][100] = {"","cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};
    char excessao[10][100] = {"","onze","doze","treze","catorze","quinze","dezesseis","dezessete","dezoito","dezenove"};


    printf("igite um numero de 1 a 999: ");
    scanf("%d", &N);

    c = N/100;
    d = (N%100)/10;
    u = (N%100)%10;

    printf("Numero digitado foi");
    if(N == 0)
    {
        printf(" zero\n");
        return 0;
    }

    if(c == 1 && d == 0 && u == 0)
    {
        printf(" cem\n");
        return 0;

    }

    printf(" %s", centena[c]);
    if(c != 0)
        printf(" e ");
    if(d == 1 && u != 0)
    {
        printf("%s" , excessao[u]);
    }else
    {
       printf("%s", dezena[d]);
       if(d != 0 && u != 0)
            printf(" e ");
       printf("%s", unidade[u]);
    }


    return 0;

}
