#include "estado.h"

int main()
{
    ESTADO e={0};
    char comando[50];
    FILE *fptr=NULL;//Nível do bot ainda não está implementado!
    abertura();
    initEstado(e);
    do {
        printf("Reversi > ");
        fgets(comando,50,stdin);
        switch(toupper(comando[0])){
            case 'N':
                resetaTabuleiro(&e,comando);
                initStack(e);
                printa(e);
                break;
            case 'A':
                impBot(&e,comando);
                initStack(e);
                printa(e);
                botPlays(&e);
                break;
            case 'J':
                if (e.jogoaberto){
                    e=head->es;
                    jogada(&e,comando);
                    printa(head->es);
                    if(e.modo=='1') printf("BOT JOGOU!\n");
                }
                else printf("Ainda não iniciou um jogo!\n");
                break;
            case 'S':
                if (e.jogoaberto){
                    jvalidas(&(head->es));
                    printa(head->es);
                    tiraPontos(&(head->es));
                }
                else printf("Ainda não iniciou um jogo!\n");
                break;
            case 'E':
                if (e.jogoaberto) writef(fptr,e,comando);
                else printf("Ainda não iniciou um jogo!\n");
                break;
            case 'L':
                e.jogoaberto=1;
                readf(fptr,&e,comando);
                initStack(e);
                printa(e);
                break;
            case 'U':
                if(e.jogoaberto){
                    pop();
                    printa(head->es);
                }
                else printf("Ainda não iniciou um jogo!\n");
                break;
            default:
                if (toupper(comando[0])!='Q') printf("Inválido!\n");
                break;
        }
        if(e.jogoaberto){
            e=head->es;
            if (tabuleirocheio(head->es) || finalJogo2(&(head->es))){
                mensagemFinal(head->es);
                e.jogoaberto=0;
            }
            head->es=e;
            if(passarVez(&(head->es))){
                mudaJogador(&(head->es));
            }
        }
    } while (toupper(comando[0])!='Q');
    mensagemSaida();
    return 0;
}