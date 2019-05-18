#include "estado.h"

void insere(int l,int c){
        Posicao new=(Posicao) malloc(sizeof(struct posicao));
        new->l=l;
        new->c=c;
        new->prox=topo;
        topo=new;
}

int tiraLinhaStack (int n){
    int i=0;
    Posicao temp=topo;
    while (i<n){
        temp=temp->prox;
        i++;
    }
    return (temp->l);
}

int tiraColunaStack (int n){
    int i=0;
    Posicao temp=topo;
    while (i<n){
        temp=temp->prox;
        i++;
    }
    return (temp->c);
}

void guardaValidas(ESTADO *e){
    int i,j;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if (e->grelha[i][j]==VAZIA && valida(i+1,j+1,e)) insere(i+1,j+1);
        }
    }
}

int length(){
    int c=0;
    Posicao temp=topo;
    while (temp){
        temp=temp->prox;
        c++;
    }
    return c;
}

void jogaBot (ESTADO *e){
    if (e->nBot==1){
        int random,linha,coluna;
       guardaValidas(e);
       //displayPos();
       random=rand()%(length()-1);
       //printf("rand:%d\n",random);
       linha=tiraLinhaStack(random);
       coluna=tiraColunaStack(random);
       //printf("l: %d,c: %d\n",linha,coluna);
       jogadaBot(e,linha,coluna);
       push(*e);
       topo=NULL;
    }
}

void jogadaBot(ESTADO *e,int l,int c){
    if (e->grelha[l-1][c-1]==VAZIA || e->grelha[l-1][c-1]==PONTO) e->grelha[l-1][c-1]=e->peca;
        virapecas(l,c,e);
        if (e->peca==VALOR_X) e->peca=VALOR_O;
        else if (e->peca==VALOR_O) e->peca=VALOR_X;
    }

    void botPlays(ESTADO *e){
        if(e->peca==VALOR_X && e->nBot) {
            jogaBot(e);
            printa(*e);
            printf("BOT JOGOU!\n");
        }
}

