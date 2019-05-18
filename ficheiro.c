#include <stdio.h>
#include "estado.h"
#include <string.h>
#include <stdlib.h>

void readf(FILE *f,ESTADO *e,char *r) {
    int i=0, j, c = 0, in=2;
    char modo,peca;
    modo=peca=' ';
    char linha[256],nomeSave[256],path[]="/home/joaopereira/CLionProjects/LI2/Projeto_Reversi/Saves/";
    while (r[in]!='\n' && r[in]){
        if(r[in]==' ') nomeSave[i]='_';
        else nomeSave[i]=r[in];
        i++;in++;
    }
    nomeSave[i]='\0';
    strcat(nomeSave,".txt");
    strcat(path,nomeSave);
    f=fopen(path,"r");
    if(!f) {printf("Ficheiro vazio!\n");return;}
    printf("Save aberto! | ");
    fscanf(f,"%c %c",&modo,&peca);
    switch (modo){
        case 'M':
            e->modo='0';
            break;
        case 'A':
            e->modo='1';
            break;
    }
    switch (peca) {
        case 'X':
            e->peca = VALOR_X;
            break;
        case 'O':
            e->peca = VALOR_O;
            break;
        default:
            e->peca = VAZIA;
            break;
    }
    fseek(f,1,SEEK_CUR);
    for (i = 0; i < 8; i++) {
        fgets(linha, 256, f);
        c=0;
        for (j = 0; linha[j] != '\n' && c < 8; j++) {
            switch (linha[j]) {
                case '-':
                    e->grelha[i][c] = VAZIA;
                    c++;
                    break;
                case 'O':
                    e->grelha[i][c] = VALOR_O;
                    c++;
                    break;
                case 'X':
                    e->grelha[i][c] = VALOR_X;
                    c++;
                    break;
            }
        }
    }
    fclose(f);
}

void writef(FILE *f,ESTADO e,char *r){
    int i,j,in;
    char modo;
    char nomeSave[256],path[]="/home/joaopereira/CLionProjects/LI2/Projeto_Reversi/Saves/";
    in=2;i=0;
    while (r[in]!='\n' && r[in]){
        if(r[in]==' ') nomeSave[i]='_';
        else nomeSave[i]=r[in];
        i++;in++;
    }
    nomeSave[i]='\0';
    strcat(nomeSave,".txt");
    strcat(path,nomeSave);
    f=fopen(path,"w");
    fseek(f,0,SEEK_SET);
    if (e.modo=='0') modo='M';
    else modo='A';
    if(e.peca==VALOR_X) fprintf(f,"%c %c\n",modo,'X');
    if(e.peca==VALOR_O) fprintf(f,"%c %c\n",modo,'O');
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
                switch (e.grelha[i][j]) {
                    case VALOR_O: {
                        fprintf(f,"O ");
                        break;
                    }
                    case VALOR_X: {
                        fprintf(f,"X ");
                        break;
                    }
                    case VAZIA: {
                        fprintf(f,"- ");
                        break;
                    }
                }
            }
        fprintf(f,"\n");
        }
    fclose(f);
}