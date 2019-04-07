#include <stdio.h>
#include "estado.h"
#include <string.h>


int main()
{
    ESTADO e = {0};
    e.modo='v'; // v representa um modo ainda não definido pelo utilizador;
    e.peca=VAZIA;
    char read[256] = "N";
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;
    //printf("%d",valida(3,5,e));
    printf("Comece um novo jogo!\n");
    while (read[0]!='Q') alteraEstado(&e,read);
    return 0;
}