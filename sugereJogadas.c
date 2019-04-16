#include <stdio.h>
#include "estado.h"
#include <string.h>
#include <stdlib.h>

void jvalidas(ESTADO *e){
    int i,j;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if (e->grelha[i][j]==VAZIA && valida(i+1,j+1,e)) e->grelha[i][j]=PONTO;
        }
    }
}

int quantasValidas(ESTADO *e) {
    int i, j, c=0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (e->grelha[i][j] == VAZIA && valida(i+1,j+1,e)) c++;
        }
    }
    return c;
}

void tiraPontos(ESTADO *e){
    int i,j;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if (e->grelha[i][j]==PONTO) e->grelha[i][j]=VAZIA;
        }
    }
}

/*void sugere(ESTADO *e){
    if (quantasValidas(e)!=0){

    }

}*/


