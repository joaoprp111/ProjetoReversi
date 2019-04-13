#include <stdio.h>
#include "estado.h"
#include <string.h>


int main()
{
    ESTADO e = {0};
    e.modo='v'; // v representa um modo ainda não definido pelo utilizador;
    e.peca=VAZIA;
    e.contagem=1;
    e.j=0;
    char read[256] = "N";//N-nulo;
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;
    //printf("%d %d\n",validaDiSS(3,6,&e),validaDiSI(3,6,&e));
    while (read[0]!='Q'){
        if(tabuleirocheio(&e)){
            if(contaO((&e))>contaX(&e)) printf("FIM DO JOGO! O VENCEDOR É O DA PEÇA O!\n");
            else printf("FIM DO JOGO! O VENCEDOR É O DA PEÇA X!\n");
            e.j=0;
        }
        if(!quantasValidas(&e) && (e.peca==VALOR_X || e.peca==VALOR_O) && e.j){
            if(e.peca==VALOR_X){
                e.peca=VALOR_O;
                if(!quantasValidas(&e)){
                    if(contaO((&e))>contaX(&e)) printf("FIM DO JOGO! O VENCEDOR É O DA PEÇA O!\n");
                    else printf("FIM DO JOGO! O VENCEDOR É O DA PEÇA X!\n");
                    e.j=0;
                }
                else e.peca=VALOR_X;
            }
        }
        if (!quantasValidas(&e) && (e.peca==VALOR_X || e.peca==VALOR_O) && e.j) {
            printf("NÃO HÁ JOGADAS POSSÍVEIS! PASSA A VEZ\n\n");
            if (e.peca==VALOR_O) e.peca=VALOR_X;
            else e.peca=VALOR_O;
            printa(&e);
            alteraEstado(&e,read);
        }
        else alteraEstado(&e,read);
    }
    return 0;
}