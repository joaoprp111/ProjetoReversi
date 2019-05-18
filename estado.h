//
// Created by pja on 27/02/2019.
//
#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador
    int jogoaberto;// 1->a decorrer, 0->ainda não iniciado
    int nBot;
} ESTADO;

/**
Stack que contém os vários estados do jogo!
*/
typedef struct lligada{
    ESTADO es;
    struct lligada *ant;
} *STACK;

STACK head;

/** Estrutura que guarda as posições das jogadas válidas */

typedef struct posicao{
    int l;
    int c;
    struct posicao *prox;
} *Posicao;

Posicao topo;

void abertura();
void printa(ESTADO e);
void jogada(ESTADO *e,char *comando);
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
int tabuleirocheio(ESTADO e);
void resetaTabuleiro(ESTADO *e,char *linha);
void virapecas(int l,int c,ESTADO *e);
void tiraPontos(ESTADO *e);
int contaO(ESTADO e);
int contaX(ESTADO e);
void writef(FILE *f,ESTADO e,char *r);
void readf(FILE *f,ESTADO *e,char *r);
int finalJogo2(ESTADO *e);
void pop();
void push(ESTADO e);
void initStack(ESTADO e);
void display();
ESTADO peek();
int isEmpty();
ESTADO initEstado(ESTADO e);
int passarVez(ESTADO *e);
void mudaJogador(ESTADO *e);
void mensagemFinal(ESTADO e);
void mensagemSaida();
void impBot(ESTADO *e, char *linha);
void guardaValidas(ESTADO *e);
void insere(int l,int c);
int tiraLinhaStack (int n);
int tiraColunaStack (int n);
void jogadaBot(ESTADO *e,int l,int c);
void jogaBot (ESTADO *e);
void botPlays(ESTADO *e);
void displayPos();

#endif //PROJ_ESTADO_H