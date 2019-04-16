#include <stdio.h>
#include "estado.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    ESTADO e = {0};
    FILE *fptr;
    fptr=NULL;
    char read[256] = "N";//N-nulo;
    abertura();
    estadoinicial(&e);
    while (read[0]!='Q'){
        finalJogo1(&e);
        finalJogo2(&e);
        alteraJogo(&e,read,fptr);
    }
    return 0;
}