//
// Created by pja on 27/02/2019.
//
#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H
#include <stdio.h>

/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, PONTO, VALOR_X, VALOR_O} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! 'M'-> manual, 'A'-> contra bot, 'v'->vazio(sem modo implementado)
    int contagem;
    int j; // verifica se o jogo está a decorrer ou não
} ESTADO;

void abertura();
void estadoinicial(ESTADO *e);
void printa(ESTADO *e);
void alteraEstado(ESTADO *e, char *r,FILE *f);
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
void jvalidas(ESTADO *e);
int quantasValidas(ESTADO *e);
int tabuleirocheio(ESTADO *e);
void resetaTabuleiro(ESTADO *e);
void tiraPontos(ESTADO *e);
int contaO(ESTADO *e);
int contaX(ESTADO *e);
void writef(FILE *f,ESTADO *e,char *r);
void readf(FILE *f,ESTADO *e,char *r);
void finalJogo1(ESTADO *e);
void finalJogo2(ESTADO *e);
void alteraJogo(ESTADO *e,char *read,FILE *fptr);


#endif //PROJ_ESTADO_H