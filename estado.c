//
// Created by pja on 28/02/2019.
//
#include <stdio.h>
#include "estado.h"
#include <string.h>

// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e)
{
    int i;
    int j;
    char c = ' ';
    if (e.modo=='m') printf("Modo: Manual | ");
    if (e.modo=='b') printf("Modo: Contra bot | ");
    if (e.peca==VALOR_X) printf("Peca atual: X\n");
    if (e.peca==VALOR_O) printf("Peca atual: O\n");
    for (i = 0; i < 8; i++) {
        printf("                                           ");
        for (j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("\n");
}

void comandos () {
    printf("\nLista de comandos para jogar:");
    printf("\n-> N <peca>(novo jogo a começar com a <peca>);\n");
    printf("-> L <ficheiro> (ler o <ficheiro>);\n");
    printf("-> E <ficheiro> (escrever no <ficheiro>);\n");
    printf("-> J <L> <C> (jogar na linha l e coluna c);\n");
    printf("-> S (imprimir jogadas válidas);\n");
    printf("-> H (sugestao de jogada);\n");
    printf("-> U (desfazer jogada);\n");
    printf("-> A <peca> <nivel> (jogar contra bot que vai usar a <peca> e de nivel <nivel>);\n");
    printf("-> Q (sair do jogo).\n");
}

ESTADO alteraEstado(ESTADO e, char *r) {
    int i,l=0,c=0;
    printf("Introduza um comando:");
    fgets(r,256,stdin);
        if (r[0]=='N' && r[2]=='X') {
            e.modo='m'; e.peca=VALOR_X;
        }
        if (r[0]=='N' && r[2]=='O') {
            e.modo='m';e.peca=VALOR_O;
        }
        if (r[0]=='A' && r[2]=='X') {
            e.modo='b';e.peca=VALOR_X;
        }
        if (r[0]=='J') {
            for (i=1;i<9;i++){if (r[2]==i+48) l=i;}
            for (i=1;i<9;i++){if (r[4]==i+48) c=i;}
            if (l!=0 && c!=0) jogada(l,c,e);
            else printf("Coordenadas inválidas!\n");
        }
        printa(e);
        return e;
    }

int validaVert (int l,int c,ESTADO e) {
    int i,foundPeca=0,livreC=1,livreB=1,j=l-1;
    if (j-1<0) livreC=0;
    else if (e.grelha[j-1][c-1]==VAZIA || e.grelha[j-1][c-1]==e.peca) livreC=0;
    i=j-2;
    if (i<0) livreC=0;
    while (i>=0 && livreC && !foundPeca) {
        if (e.grelha[i][c-1]==VAZIA) livreC=0;
        if (e.grelha[i][c-1]==e.peca) foundPeca=1;
        i--;
    }
    if (livreC) return 1;
    else {
        foundPeca = 0;
        if (j+1>=8) livreB = 0;
        else if (e.grelha[j+1][c-1]==VAZIA || e.grelha[j+1][c-1]==e.peca) livreB=0;
        i=j+2;
        if (i>=8) livreB=0;
        while (i<8 && livreB && !foundPeca) {
            if (e.grelha[i][c-1]==VAZIA) livreB=0;
            if (e.grelha[i][c-1]==e.peca) foundPeca=1;
            i++;
        }
    }
        return (livreC || livreB);
}

int validaHoriz (int l,int c,ESTADO e){
    int i,foundPeca=0,livreD=1,livreE=1,j=c-1;
    if (j-1<0) livreE=0;
    else if (e.grelha[l-1][j-1]==VAZIA || e.grelha[l-1][j-1]==e.peca) livreE=0;
    i=j-2;
    if (i<0) livreE=0;
    while (i>=0 && livreE && !foundPeca){
        if (e.grelha[l-1][i]==VAZIA) livreE=0;
        if (e.grelha[l-1][i]==e.peca) foundPeca=1;
        i--;
    }
    if (livreE) return 1;
    else {
        foundPeca = 0;
        if (j+1>=8) livreD = 0;
        else if (e.grelha[l-1][j+1]==VAZIA || e.grelha[l-1][j+1]==e.peca) livreD=0;
        i=j+2;
        if (i>=8) livreD=0;
        while (i<8 && livreD && !foundPeca) {
            if (e.grelha[l-1][i]==VAZIA) livreD=0;
            if (e.grelha[l-1][i]==e.peca) foundPeca=1;
            i++;
        }
    }
    return (livreD || livreE);
}

int validaDiP(int l,int c,ESTADO e){
    int i,j,foundPeca=0,livreS=1,livreI=1,jl=l-1,jc=c-1;
    if (jl-1<0 || jc-1<0) livreS=0;
    else if (e.grelha[jl-1][jc-1]==VAZIA || e.grelha[jl-1][jc-1]==e.peca) livreS=0;
    i=jl-2; j=jc-2;
    if (i<0 || j<0) livreS=0;
    while (i>=0 && j>=0 && livreS && !foundPeca){
        if (e.grelha[i][j]==VAZIA) livreS=0;
        if (e.grelha[i][j]==e.peca) foundPeca=1;
        i--;j--;
    }
    if (livreS) return 1;
    else {
        foundPeca=0;
        if (jl+1>=8 || jc+1>=8) livreI=0;
        else if(e.grelha[jl+1][jc+1]==VAZIA || e.grelha[jl+1][jc+1]==e.peca) livreI=0;
        i=jl+2;j=jc+2;
        while (i<8 && j<8 && livreI && !foundPeca){
            if (e.grelha[i][j]==VAZIA) livreI=0;
            if (e.grelha[i][j]==e.peca) foundPeca=1;
            i++;j++;
        }
    }
    return (livreI || livreS);
}

int validaDiS(int l,int c,ESTADO e){
    int i,j,foundPeca=0,livreS=1,livreI=1,jl=l-1,jc=c-1;
    if (jl-1<0 || jc+1>=8) livreS=0;
    else if (e.grelha[jl-1][jc+1]==VAZIA || e.grelha[jl-1][jc+1]==e.peca) livreS=0;
    i=jl-2; j=jc+2;
    if (i<0 || j>=8) livreS=0;
    while (i>=0 && j<8 && livreS && !foundPeca){
        if (e.grelha[i][j]==VAZIA) livreS=0;
        if (e.grelha[i][j]==e.peca) foundPeca=1;
        i--;j++;
    }
    if (livreS) return 1;
    else {
        foundPeca=0;
        if (jl+1>=8 || jc-1<0) livreI=0;
        else if(e.grelha[jl+1][jc-1]==VAZIA || e.grelha[jl+1][jc-1]==e.peca) livreI=0;
        i=jl+2;j=jc-2;
        while (i<8 && j>=0 && livreI && !foundPeca){
            if (e.grelha[i][j]==VAZIA) livreI=0;
            if (e.grelha[i][j]==e.peca) foundPeca=1;
            i++;j--;
        }
    }
    return (livreI || livreS);
}

int valida(int l,int c,ESTADO e){
    return (validaHoriz(l,c,e) || validaVert(l,c,e) || validaDiP(l,c,e) || validaDiS(l,c,e));
}

void jogada(int l,int c,ESTADO e){
    int i,j;
    printf("%d",valida(l,c,e));
    if (valida(l,c,e)) {
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if (i==l-1 && j==c-1) e.grelha[i][j]=e.peca;
            }
        }
    }
    else printf("Jogada inválida!\n");
}


