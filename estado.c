//
// Created by pja on 28/02/2019.
//
#include <stdio.h>
#include "estado.h"
#include <string.h>
#include <stdlib.h>

void estadoinicial(ESTADO *e){
    e->modo='v'; // v representa um modo ainda não definido pelo utilizador;
    e->peca=VAZIA;
    e->contagem=1;
    e->j=0;
    e->grelha[3][4] = VALOR_X;
    e->grelha[4][3] = VALOR_X;
    e->grelha[3][3] = VALOR_O;
    e->grelha[4][4] = VALOR_O;
}

void abertura(){
    printf("\n\n");
    printf("__________________________________________________________________\n");
    printf("                       __|REVERSI|__                \n");
    printf("-> Crie um novo jogo ou carregue um já salvo na pasta 'Saves' <-\n");
    printf("-> Se salvar o seu jogo ele será salvo na respetiva pasta <-\n");
    printf("__________________________________________________________________\n");
    printf("\n\n");
}

void resetaTabuleiro(ESTADO *e){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            e->grelha[i][j]=VAZIA;
        }
    }
    e->modo='v'; // v representa um modo ainda não definido pelo utilizador;
    e->peca=VAZIA;
    e->contagem=1;
    e->j=0;
    e->grelha[3][4] = VALOR_X;
    e->grelha[4][3] = VALOR_X;
    e->grelha[3][3] = VALOR_O;
    e->grelha[4][4] = VALOR_O;
}

// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO *e)
{
    int i;
    int j;
    char c = ' ';
    if (e->j){
        if (e->modo=='M') printf("Modo: Manual | ");
        if (e->modo=='A') printf("Modo: Automático | ");
        if (e->peca==VALOR_X) printf("Jogador: X | ");
        if (e->peca==VALOR_O) printf("Jogador: O | ");
        printf("Jogada: %d | ",e->contagem);
        printf("SCOREBOARD (X) %d (O) %d \n",contaX(e),contaO(e));
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
                        c = '*';
                        break;
                }
                printf("%c ", c);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void alteraEstado(ESTADO *e, char *r,FILE *f) {
    int i, l = 0, c = 0;
    if (!(e->j)) printf("Comece um novo jogo ou abra um dos saves!\n");
    printf("Introduza um comando:");
    fgets(r, 256, stdin);
    if (r[0] == 'N' && r[2] == 'X') {
        printf("JOGO INICIADO! | ");
        resetaTabuleiro(e);
        e->modo = 'M';
        e->peca = VALOR_X;
        e->j = 1;
    }
    if (r[0] == 'N' && r[2] == 'O') {
        printf("JOGO INICIADO! | ");
        resetaTabuleiro(e);
        e->modo = 'M';
        e->peca = VALOR_O;
        e->j = 1;
    }
    if (r[0] == 'A' && r[2] == 'X') {
        printf("JOGO INICIADO! | ");
        resetaTabuleiro(e);
        e->modo = 'A';
        e->peca = VALOR_X;
        e->j = 1;
    }
    if (r[0] == 'J' && e->modo != 'v') { //só entra neste caso se o modo de jogo já tiver sido selecionado
        for (i = 1; i < 9; i++) { if (r[2] == i + 48) l = i; }
        for (i = 1; i < 9; i++) { if (r[4] == i + 48) c = i; }
        if (l != 0 && c != 0) jogada(l, c, e);
        else printf("Coordenadas inválidas!\n");
    }
    if (r[0] == 'S' && e->modo != 'v' && e->j) {
        jvalidas(e);
    }
    if (r[0] == 'E' && !(e->j)) printf("Ainda não iniciou um jogo!\n");
    if (r[0] == 'E' && e->j) writef(f,e,r);
    if (r[0] == 'L') readf(f,e,r);
    if (r[0] != 'Q') printa(e);
    tiraPontos(e);
}

void finalJogo1(ESTADO *e){
    if(tabuleirocheio(e)){
        if(contaO(e)>contaX(e)) printf("FIM DO JOGO! O VENCEDOR É O DA PEÇA O!\n");
        else printf("FIM DO JOGO! O VENCEDOR É O DA PEÇA X!\n");
        e->j=0;
    }
}

void finalJogo2(ESTADO *e){
    if(!quantasValidas(e) && (e->peca==VALOR_X || e->peca==VALOR_O) && e->j){
        if(e->peca==VALOR_X){
            e->peca=VALOR_O;
            if(!quantasValidas(e)){
                if(contaO(e)>contaX(e)) printf("FIM DO JOGO! O VENCEDOR É O DA PEÇA O!\n");
                else printf("FIM DO JOGO! O VENCEDOR É O DA PEÇA X!\n");
                e->j=0;
            }
            else e->peca=VALOR_X;
        }
    }
}

void alteraJogo(ESTADO *e,char *read,FILE *fptr){
    if (!quantasValidas(e) && (e->peca==VALOR_X || e->peca==VALOR_O) && e->j) {
        printf("NÃO HÁ JOGADAS POSSÍVEIS! PASSA A VEZ\n\n");
        if (e->peca==VALOR_O) e->peca=VALOR_X;
        else e->peca=VALOR_O;
        printa(e);
        alteraEstado(e,read,fptr);
    }
    else alteraEstado(e,read,fptr);
}


