//
// Created by pja on 28/02/2019.
//
#include <stdio.h>
#include "estado.h"
#include <string.h>

// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO *e)
{
    int i;
    int j;
    char c = ' ';
    if (e->modo=='m') printf("Modo: Manual | ");
    if (e->modo=='b') printf("Modo: Contra bot | ");
    if (e->peca==VALOR_X) printf("Peca atual: X\n");
    if (e->peca==VALOR_O) printf("Peca atual: O\n");
    printf("                                           . ");
    for (i=0;i<8;i++) printf("%d ",(i+1));
    printf("\n");
    for (i = 0; i < 8; i++) {
        printf("                                          %d  ",(i+1));
        for (j = 0; j < 8; j++) {
            switch (e->grelha[i][j]) {
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
                case PONTO:
                    c = '.';
                    break;
            }
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("\n");
}

void alteraEstado(ESTADO *e, char *r) {
    int i,l=0,c=0;
    printf("Introduza um comando:");
    fgets(r,256,stdin);
        if (r[0]=='N' && r[2]=='X') {
            printf("JOGO INICIADO! | ");
            e->modo='m'; e->peca=VALOR_X;
        }
        if (r[0]=='N' && r[2]=='O') {
            printf("JOGO INICIADO! | ");
            e->modo='m';e->peca=VALOR_O;
        }
        if (r[0]=='A' && r[2]=='X') {
            printf("JOGO INICIADO! | ");
            e->modo='b';e->peca=VALOR_X;
        }
        if (r[0]=='J' && e->modo!='v') { //só entra neste caso se o modo de jogo já tiver sido selecionado
            for (i=1;i<9;i++){if (r[2]==i+48) l=i;}
            for (i=1;i<9;i++){if (r[4]==i+48) c=i;}
            if (l!=0 && c!=0) jogada(l,c,e);
            else printf("Coordenadas inválidas!\n");
        }
        if (r[0]=='S' && e->modo!='v') {
            jvalidas(e);
        }
        if (r[0]!='Q') printa(e);
        tiraPontos(e);
    }

