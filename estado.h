//
// Created by pja on 27/02/2019.
//



#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H



/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! 'm'-> manual, 'b'-> contra bot
} ESTADO;


void printa(ESTADO *e);
void alteraEstado(ESTADO *e, char *r);
void jogada(int l,int c,ESTADO *e);
int validaVertC(int l,int c,ESTADO *e);
int validaVertB(int l,int c,ESTADO *e);
int validaVert(int l,int c,ESTADO *e);
int validaHorizE(int l,int c,ESTADO *e);
int validaHorizD(int l,int c,ESTADO *e);
int validaHoriz(int l,int c,ESTADO *e);
int validaDiPS(int l,int c,ESTADO *e);
int validaDiPI(int l,int c,ESTADO *e);
int validaDiP(int l,int c,ESTADO *e);
int validaDiSS(int l,int c,ESTADO *e);
int validaDiSI(int l,int c,ESTADO *e);
int validaDiS(int l,int c,ESTADO *e);
int valida(int l,int c,ESTADO *e);


#endif //PROJ_ESTADO_H