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
            e->modo='m'; e->peca=VALOR_X;
        }
        if (r[0]=='N' && r[2]=='O') {
            e->modo='m';e->peca=VALOR_O;
        }
        if (r[0]=='A' && r[2]=='X') {
            e->modo='b';e->peca=VALOR_X;
        }
        if (r[0]=='J') {
            for (i=1;i<9;i++){if (r[2]==i+48) l=i;}
            for (i=1;i<9;i++){if (r[4]==i+48) c=i;}
            if (l!=0 && c!=0) jogada(l,c,e);
            else printf("Coordenadas inválidas!\n");
        }
        printa(e);
    }

