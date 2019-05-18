#include "estado.h"

void push(ESTADO e){
    STACK newNode=(STACK) malloc(sizeof(struct lligada));
    newNode->es=e;
    newNode->ant=head;
    head=newNode;
}

int isEmpty(){
    return (!head);
}

ESTADO peek(){
    if(!isEmpty()){
        return head->es;
    }
}

void pop(){
    STACK newNode;
    if(!head) printf("Stack Vazia\n");
    else if (!(head->ant)) printf("Já está no primeiro estado!\n");
    else {
        newNode=head;
        head=head->ant;
        free(newNode);
    }
}

void display(){
    STACK temp;
    if (!head) printf("Stack vazia\n");
    else {
        temp=head;
        while(temp){
            printf("Nodo:\n");
            printa(temp->es);
            putchar('\n');
            temp=temp->ant;
        }
        printf("NULL\n");
    }
}

void displayPos(){
    Posicao temp;
    if (!topo) printf("Stack vazia\n");
    else {
        temp=topo;
        while(temp){
            printf("Nodo:\n");
            printf("l:%d\n",temp->l);
            printf("c:%d\n",temp->c);
            temp=temp->prox;
        }
        printf("NULL\n");
    }
}

void initStack(ESTADO e){
    STACK newNode=(STACK) malloc(sizeof(struct lligada));
    newNode->es=e;
    newNode->ant=NULL;
    head=newNode;
}
