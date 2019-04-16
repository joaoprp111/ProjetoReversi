#include <stdio.h>
#include "estado.h"
#include <string.h>
#include <stdlib.h>

int tabuleirocheio(ESTADO *e){
    int i,j,cheio=1;
    for(i=0;i<8 && cheio;i++){
        for(j=0;j<8 && cheio;j++){
            if (e->grelha[i][j]==VAZIA || e->grelha[i][j]==PONTO) cheio=0;
        }
    }
    return cheio;
}

//VALIDAR JOGADAS NA VERTICAL-INICIO

int validaVertC(int l,int c,ESTADO *e) {
    int i,j=l-1,foundPeca=0,livreC=1;
    if (j - 1 < 0) livreC = 0;
    else if (e->grelha[j-1][c-1]==VAZIA || e->grelha[j-1][c-1]==PONTO || e->grelha[j-1][c-1]==e->peca) livreC = 0;
    i=j-2;
    if (i < 0) livreC = 0;
    while (i >= 0 && livreC && !foundPeca) {
        if (e->grelha[i][c-1]==VAZIA || e->grelha[i][c-1]==PONTO) livreC = 0;
        if (e->grelha[i][c-1]==e->peca) foundPeca = 1;
        i--;
    }
    if (livreC && !foundPeca) livreC=0;
    return livreC;
}

int validaVertB(int l,int c,ESTADO *e){
    int foundPeca=0,j=l-1,i,livreB=1;
    if (j+1>=8) livreB = 0;
    else if (e->grelha[j+1][c-1]==VAZIA || e->grelha[j+1][c-1]==PONTO || e->grelha[j+1][c-1]==e->peca) livreB=0;
    i=j+2;
    if (i>=8) livreB=0;
    while (i<8 && livreB && !foundPeca) {
        if (e->grelha[i][c-1]==VAZIA || e->grelha[i][c-1]==PONTO) livreB=0;
        if (e->grelha[i][c-1]==e->peca) foundPeca=1;
        i++;
    }
    if (livreB && !foundPeca) livreB=0;
    return livreB;
}



int validaVert (int l,int c,ESTADO *e) {
    return (validaVertC(l,c,e) || validaVertB(l,c,e));
}

// VALIDAR JOGADAS NA VERTICAL-FIM
// VALIDAR JOGADAS NA HORIZONTAL-INICIO

int validaHorizE(int l,int c,ESTADO *e){
    int i,j=c-1,livreE=1,foundPeca=0;
    if (j-1<0) livreE=0;
    else if (e->grelha[l-1][j-1]==VAZIA || e->grelha[l-1][j-1]==PONTO || e->grelha[l-1][j-1]==e->peca) livreE=0;
    i=j-2;
    if (i<0) livreE=0;
    while (i>=0 && livreE && !foundPeca){
        if (e->grelha[l-1][i]==VAZIA || e->grelha[l-1][i]==PONTO) livreE=0;
        if (e->grelha[l-1][i]==e->peca) foundPeca=1;
        i--;
    }
    if(livreE && !foundPeca) livreE=0;
    return livreE;
}

int validaHorizD(int l,int c,ESTADO *e){
    int i,j=c-1,foundPeca=0,livreD=1;
    if (j+1>=8) livreD = 0;
    else if (e->grelha[l-1][j+1]==VAZIA || e->grelha[l-1][j+1]==PONTO || e->grelha[l-1][j+1]==e->peca) livreD=0;
    i=j+2;
    if (i>=8) livreD=0;
    while (i<8 && livreD && !foundPeca) {
        if (e->grelha[l-1][i]==VAZIA || e->grelha[l-1][i]==PONTO) livreD=0;
        if (e->grelha[l-1][i]==e->peca) foundPeca=1;
        i++;
    }
    if(livreD && !foundPeca)livreD=0;
    return livreD;
}

int validaHoriz (int l,int c,ESTADO *e){
    return (validaHorizD(l,c,e) || validaHorizE(l,c,e));
}

// VALIDAR JOGADAS NA HORIZONTAL-FIM
// VALIDAR JOGADAS NA DIAGONAL PRINCIPAL-INICIO

int validaDiPS(int l,int c,ESTADO *e){
    int i,j,jl=l-1,jc=c-1,foundPeca=0,livreS=1;
    if (jl-1<0 || jc-1<0) livreS=0;
    else if (e->grelha[jl-1][jc-1]==VAZIA || e->grelha[jl-1][jc-1]==PONTO || e->grelha[jl-1][jc-1]==e->peca) livreS=0;
    i=jl-2; j=jc-2;
    if (i<0 || j<0) livreS=0;
    while (i>=0 && j>=0 && livreS && !foundPeca){
        if (e->grelha[i][j]==VAZIA || e->grelha[i][j]==PONTO) livreS=0;
        if (e->grelha[i][j]==e->peca) foundPeca=1;
        i--;j--;
    }
    if(livreS && !foundPeca)livreS=0;
    return livreS;
}

int validaDiPI(int l,int c,ESTADO *e){
    int i,j,jl=l-1,jc=c-1,foundPeca=0,livreI=1;
    if (jl+1>=8 || jc+1>=8) livreI=0;
    else if(e->grelha[jl+1][jc+1]==VAZIA || e->grelha[jl+1][jc+1]==PONTO || e->grelha[jl+1][jc+1]==e->peca) livreI=0;
    i=jl+2;j=jc+2;
    while (i<8 && j<8 && livreI && !foundPeca){
        if (e->grelha[i][j]==VAZIA || e->grelha[i][j]==PONTO) livreI=0;
        if (e->grelha[i][j]==e->peca) foundPeca=1;
        i++;j++;
    }
    if(livreI && !foundPeca)livreI=0;
    return livreI;
}

int validaDiP(int l,int c,ESTADO *e){
    return (validaDiPS(l,c,e) || validaDiPI(l,c,e));
}

// VALIDAR JOGADAS NA DIAGONAL PRINCIPAL-FIM
// VALIDAR JOGADAS NA DIAGONAL SECUNDARIA-INICIO

int validaDiSS(int l,int c,ESTADO *e){
    int i,j,jl=l-1,jc=c-1,foundPeca=0,livreS=1;
    if (jl-1<0 || jc+1>=8) livreS=0;
    else if (e->grelha[jl-1][jc+1]==VAZIA || e->grelha[jl-1][jc+1]==PONTO || e->grelha[jl-1][jc+1]==e->peca) livreS=0;
    i=jl-2; j=jc+2;
    if (i<0 || j>=8) livreS=0;
    while (i>=0 && j<8 && livreS && !foundPeca){
        if (e->grelha[i][j]==VAZIA || e->grelha[i][j]==PONTO) livreS=0;
        if (e->grelha[i][j]==e->peca) foundPeca=1;
        i--;j++;
    }
    if(livreS && !foundPeca)livreS=0;
    return livreS;
}

int validaDiSI(int l,int c,ESTADO *e){
    int i,j,jl=l-1,jc=c-1,livreI=1,foundPeca=0;
    if (jl+1>=8 || jc-1<0) livreI=0;
    else if(e->grelha[jl+1][jc-1]==VAZIA || e->grelha[jl+1][jc-1]==PONTO || e->grelha[jl+1][jc-1]==e->peca) livreI=0;
    i=jl+2;j=jc-2;
    while (i<8 && j>=0 && livreI && !foundPeca){
        if (e->grelha[i][j]==VAZIA || e->grelha[i][j]==PONTO) livreI=0;
        if (e->grelha[i][j]==e->peca) foundPeca=1;
        i++;j--;
    }
    if(livreI && !foundPeca)livreI=0;
    return livreI;
}

int validaDiS(int l,int c,ESTADO *e){
    return (validaDiSI(l,c,e) || validaDiSS(l,c,e));
}

// VALIDAR JOGADAS NA DIAGONAL SECUNDARIA-FIM
// VALIDAR JOGADAS TODAS-INICIO

int valida(int l,int c,ESTADO *e){
    return (validaHoriz(l,c,e) || validaVert(l,c,e) || validaDiP(l,c,e) || validaDiS(l,c,e));
}

// VALIDAR JOGADAS TODAS-FIM
// VIRAR AS PECAS-INICIO

void virapecas(int l,int c,ESTADO *e){
    int i,j;
    if (validaDiS(l,c,e)) {
        if (validaDiSS(l,c,e)) {
            for(i=l-2,j=c;i>=0 && j<8 && e->grelha[i][j]!=e->peca && e->grelha[i][j]!=VAZIA && e->grelha[i][j]!=PONTO;i--,j++) {
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_X) e->grelha[i][j]=VALOR_X;
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_O) e->grelha[i][j]=VALOR_O;
            }
        }
        if (validaDiSI(l,c,e)){
            for (i=l,j=c-2;i<8 && j>=0 && e->grelha[i][j]!=e->peca && e->grelha[i][j]!=VAZIA && e->grelha[i][j]!=PONTO;i++,j--){
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_X) e->grelha[i][j]=VALOR_X;
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_O) e->grelha[i][j]=VALOR_O;
            }
        }
    }
    if (validaDiP(l,c,e)){
        if (validaDiPS(l,c,e)){
            for(i=l-2,j=c-2;i>=0 && j>=0 && e->grelha[i][j]!=e->peca && e->grelha[i][j]!=VAZIA && e->grelha[i][j]!=PONTO;i--,j--) {
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_X) e->grelha[i][j]=VALOR_X;
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_O) e->grelha[i][j]=VALOR_O;
            }
        }
        if (validaDiPI(l,c,e)){
            for (i=l,j=c;i<8 && j<8 && e->grelha[i][j]!=e->peca && e->grelha[i][j]!=VAZIA && e->grelha[i][j]!=PONTO;i++,j++){
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_X) e->grelha[i][j]=VALOR_X;
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_O) e->grelha[i][j]=VALOR_O;
            }
        }
    }
    if (validaVert(l,c,e)){
        if (validaVertC(l,c,e)){
            for(i=l-2,j=c-1;i>=0 && e->grelha[i][j]!=e->peca && e->grelha[i][j]!=VAZIA && e->grelha[i][j]!=PONTO;i--) {
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_X) e->grelha[i][j]=VALOR_X;
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_O) e->grelha[i][j]=VALOR_O;
            }
        }
        if (validaVertB(l,c,e)){
            for (i=l,j=c-1;i<8 && e->grelha[i][j]!=e->peca && e->grelha[i][j]!=VAZIA && e->grelha[i][j]!=PONTO;i++){
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_X) e->grelha[i][j]=VALOR_X;
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_O) e->grelha[i][j]=VALOR_O;
            }
        }
    }
    if (validaHoriz(l,c,e)){
        if (validaHorizE(l,c,e)){
            for (i=l-1,j=c-2;j>=0 && e->grelha[i][j]!=e->peca && e->grelha[i][j]!=VAZIA && e->grelha[i][j]!=PONTO;j--){
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_X) e->grelha[i][j]=VALOR_X;
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_O) e->grelha[i][j]=VALOR_O;
            }
        }
        if (validaHorizD(l,c,e)){
            for (i=l-1,j=c;j<8 && e->grelha[i][j]!=e->peca && e->grelha[i][j]!=VAZIA && e->grelha[i][j]!=PONTO;j++){
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_X) e->grelha[i][j]=VALOR_X;
                if (e->grelha[i][j]!=e->peca && e->peca==VALOR_O) e->grelha[i][j]=VALOR_O;
            }
        }
    }
}

// VIRAR AS PECAS-FIM

void jogada(int l,int c,ESTADO *e){
    int i,j;
    if (valida(l,c,e)) {
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if (i==l-1 && j==c-1) e->grelha[i][j]=e->peca;
            }
        }
        virapecas(l,c,e);
        if (e->peca==VALOR_X) e->peca=VALOR_O;
        else if (e->peca==VALOR_O) e->peca=VALOR_X;
    }
    else printf("JOGADA INVÁLIDA! | ");
    e->contagem++;
}

