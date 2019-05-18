#include "estado.h"
#include <stdio.h>
#include <stdlib.h>

int contaX(ESTADO e){
    int i,j,c=0;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++){
            if (e.grelha[i][j]==VALOR_X) c++;
        }
    }
    return c;
}

int contaO(ESTADO e){
    int i,j,c=0;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++){
            if (e.grelha[i][j]==VALOR_O) c++;
        }
    }
    return c;
}

