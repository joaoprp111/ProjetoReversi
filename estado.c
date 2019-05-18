//
// Created by pja on 28/02/2019.
//
#include <stdio.h>
#include "estado.h"
#include <string.h>
#include <stdlib.h>

void abertura(){
    printf("\n\n");
    printf("                                        __________________________________________________________________\n");
    printf("                                                                   __|REVERSI|__                \n");
    printf("                                         -> Crie um novo jogo ou carregue um já salvo na pasta 'Saves' <-\n");
    printf("                                         -> Se salvar o seu jogo ele será salvo na respetiva pasta <-\n");
    printf("                                        __________________________________________________________________\n");
    printf("\n\n");
}

ESTADO initEstado(ESTADO e){
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;
    e.nBot=0;
    e.jogoaberto=0;
    return e;
}

void resetaTabuleiro(ESTADO *e, char *linha){
    int i,j;
    switch(toupper(linha[2])){
        case 'X':
            e->peca=VALOR_X;
            break;
        case 'O':
            e->peca=VALOR_O;
            break;
        default:
            printf("Comando inválido!\n");
            break;
    }
    if (e->peca==VALOR_O || e->peca==VALOR_X) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                e->grelha[i][j] = VAZIA;
            }
        }
        e->modo = '0';
        e->grelha[3][4] = VALOR_X;
        e->grelha[4][3] = VALOR_X;
        e->grelha[3][3] = VALOR_O;
        e->grelha[4][4] = VALOR_O;
        e->jogoaberto=1;
    }
}

// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e)
{
    int i;
    int j;
    char c = ' ';
    if (e.jogoaberto){
        if (e.modo=='0') printf("Modo: Manual | ");
        if (e.modo=='1'){
            printf("Modo: Automático | ");
            printf("Nível: %d | ",e.nBot);
        }
        if (e.peca==VALOR_X) printf("Peca a jogar: X | ");
        if (e.peca==VALOR_O) printf("Peca a jogar: O | ");
        printf("SCOREBOARD (X) %d (O) %d \n",contaX(e),contaO(e));
        printf("                                           . ");
        for (i=0;i<8;i++) printf("%d ",(i+1));
        printf("\n");
        for (i = 0; i < 8; i++) {
            printf("                                          %d  ",(i+1));
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
    }


int finalJogo2(ESTADO *e){
    int res=0;
    if(!quantasValidas(e) && (e->peca==VALOR_X || e->peca==VALOR_O)){
        if(e->peca==VALOR_X){
            e->peca=VALOR_O;
            if(!quantasValidas(e)) res=1;
        }
    }
    return res;
}

int passarVez(ESTADO *e) {
    int res=0;
        if (!quantasValidas(e) && (e->peca == VALOR_X || e->peca == VALOR_O)) res=1;
    return  res;
}

void mudaJogador(ESTADO *e){
    if (e->peca==VALOR_X) e->peca=VALOR_O;
    else if (e->peca==VALOR_O) e->peca=VALOR_X;
}

void mensagemFinal(ESTADO e){
    if(contaX(e)>contaO(e)) printf("--- FIM DO JOGO! --- O VENCEDOR É O JOGADOR X!\n");
    else if(contaX(e)<contaO(e)) printf("--- FIM DO JOGO! --- O VENCEDOR É O JOGADOR O!\n");
    else printf("--- FIM DO JOGO! --- EMPATE!\n");
}

void mensagemSaida(){
    printf("                                        __________________________________________________________________\n");
    printf("\n");
    printf("                                                                   __|REVERSI|__\n");
    printf("                                        __________________________________________________________________\n");
}

/** Funções para o bot */

void impBot(ESTADO *e, char *linha){
    int i,j;
    switch(toupper(linha[2])){
        case 'X':
            e->peca=VALOR_X;
            break;
        case 'O':
            e->peca=VALOR_O;
            break;
        default:
            printf("Comando inválido!\n");
            break;
    }
    switch(toupper(linha[4])){
        case '1':
            e->nBot=1;
            break;
        case '2':
            e->nBot=2;
            break;
        case '3':
            e->nBot=3;
            break;
        default:
            printf("Comando inválido!\n");
            break;
    }
    if(e->nBot && (e->peca==VALOR_X || e->peca==VALOR_O)){
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                e->grelha[i][j]=VAZIA;
            }
        }
        e->modo='1';
        e->grelha[3][4] = VALOR_X;
        e->grelha[4][3] = VALOR_X;
        e->grelha[3][3] = VALOR_O;
        e->grelha[4][4] = VALOR_O;
        e->jogoaberto=1;
    }
}


