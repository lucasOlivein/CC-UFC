#include "calcgamelib.h"
#include <stdlib.h>
#include <ncurses.h>


int show_window(int yMax, int xMax, WINDOW *printwin, const char *filename){
    FILE *arq = fopen(filename, "r");
    checkNULL(arq);
    char read_string[128];
    while(fgets(read_string,sizeof(read_string),arq) != NULL)
        wprintw(printwin, read_string);   
    wrefresh(printwin);
    return 0;
}

void gerador(struct DADOS play){
   // WINDOWS * screen = newwin(LINES, COLS, 0, 0);
   wclear(stdscr);
   wrefresh(stdscr);
    int movimentos = play.operacoes;
    printw("\nGOAL: %d\n\n", play.RESULTADO);
    refresh();
    
    int aux = play.OP_NUMEROS[0];
    printw("atual : %d    Movimentos:%d\n", aux, movimentos);
    refresh();
    for(int i=0; i<play.operacoes; i++){
        if(play.OP_ORDEM[i] == 0){
            printw("%d: + %d\n", i+1, play.OP_NUMEROS[i+1]);
            refresh();
        }
        if(play.OP_ORDEM[i] == 1){
            printw("%d: * %d\n", i+1, play.OP_NUMEROS[i+1]);
            refresh();
        }
        if(play.OP_ORDEM[i] == 2){
            printw("%d: / %d\n", i+1, play.OP_NUMEROS[i+1]);
            refresh();
        }
        if(play.OP_ORDEM[i] == 3)
            printw("%d: - %d\n", i+1, play.OP_NUMEROS[i+1]);
        if(play.OP_ORDEM[i] == 4)
            printw("%d: -> %d\n", i+1, play.OP_NUMEROS[i+1]);
    }   
    int tecla;
        while(1){
        tecla = getchar();
        getchar();
        
        if(tecla == '1'){
            if(play.OP_ORDEM[0] == 0)
                aux = aux + play.OP_NUMEROS[1];
            if(play.OP_ORDEM[0] == 1)
            aux = aux * play.OP_NUMEROS[1];
            if(play.OP_ORDEM[0] == 2)
            aux = aux / play.OP_NUMEROS[1];
            if(play.OP_ORDEM[0] == 3)
            aux = aux - play.OP_NUMEROS[1];
        }
        if(tecla == '2'){
            if(play.OP_ORDEM[1] == 0)
                aux = aux + play.OP_NUMEROS[2];
            if(play.OP_ORDEM[1] == 1)
            aux = aux * play.OP_NUMEROS[2];
            if(play.OP_ORDEM[1] == 2)
            aux = aux / play.OP_NUMEROS[2];
            if(play.OP_ORDEM[1] == 3)
            aux = aux - play.OP_NUMEROS[2];
        }
        if(tecla == '3'){

             if(play.OP_ORDEM[2] == 0)
                aux = aux + play.OP_NUMEROS[3];
            if(play.OP_ORDEM[2] == 1)
            aux = aux * play.OP_NUMEROS[3];
            if(play.OP_ORDEM[2] == 2)
            aux = aux / play.OP_NUMEROS[3];
            if(play.OP_ORDEM[2] == 3)
            aux = aux - play.OP_NUMEROS[3];
        

        }
        refresh();
        /*if(tecla == 'h')
           printar(play)*/
         movimentos--;
         move(0, 0);
        printw("atual : %d    Movimentos: %d\n", aux, movimentos);
        if(movimentos==0){
            if(aux == play.RESULTADO){
                printw("------PARABENS VOCE PASSOU--------\n");
                getchar();
                suviver(4, 1);
                break;
            }else{
                printw("-------REPROVADO-------\nQUER TENTAR DNV?? ");
                tecla = getchar();
                getchar();
                if(tecla == 's'){
                    printw("---------------------------------");
                    gerador(play);
                }else    
                    exit(1);
        }
        }
        }
        printw("DE NOVO?\n");
        tecla = getchar();
        getchar();
        if(tecla == 's')
            suviver(4, 1);
        else
            printw("REPROVADO");
    }

    struct DADOS suviver(int Movimentos, int nivel){
    struct DADOS modo_suviver;
    int Num_OP = Movimentos-1;
    int v_aux[Movimentos];
    int ORDE1M_OP[Num_OP];

    int mult, soma, div, sub, Num_OPType;
    CONSTANTES(nivel, &mult, &soma, &div, &sub, &modo_suviver.OP_NUMEROS[0], &Num_OPType,  Movimentos);
    //Definindo a ordem das operacaoes e os numeros ao qual serao aplicados//
    for(int i=0; i<Num_OP; i++){
        modo_suviver.OP_ORDEM[i] = rand()%Num_OPType;  
    }

    int aux = modo_suviver.OP_NUMEROS[0];
    for(int i=0;i < Num_OP; i++){
        switch(modo_suviver.OP_ORDEM[i]){
                case 0:
                        modo_suviver.OP_NUMEROS[i+1] = 2 + rand()%soma; 
                        aux = aux + modo_suviver.OP_NUMEROS[i+1];
                        break;
                case 1:
                        modo_suviver.OP_NUMEROS[i+1] = 2 + rand()%mult;
                        aux = aux * modo_suviver.OP_NUMEROS[i+1];
                        break;
                case 2:
                        modo_suviver.OP_NUMEROS[i+1] = 2 + rand()%div;
                        aux = aux / modo_suviver.OP_NUMEROS[i+1];
                        break;
                case 3:
                        modo_suviver.OP_NUMEROS[i+1] = 2 + rand()%sub;
                        aux = aux - modo_suviver.OP_NUMEROS[i+1];
                break;
            }
    }
    modo_suviver.RESULTADO = aux;
    modo_suviver.operacoes = Num_OP;

        op_ajustes(modo_suviver);
       gerador(modo_suviver);
        return modo_suviver;
}
void CONSTANTES(int nivel, int *mult, int  *soma, int *div, int *sub, int *first, int *Num_OPType, int Num_OP){
    switch(nivel){
        case 1:
            *first =  2 + rand()%5;
            *mult = 9;
            *soma = 5;
            *div = 8;
            *sub = 19;
            *Num_OPType = 2;
            break;
        
        case 2:
            *first = 2+ rand()%13;
            *mult = 14;
            *soma = 29;
            *div = 14;
            *sub = 29;
            *Num_OPType = 3;
            break;
        
        case 3:
            *first = 2 + rand()%18;
            *mult = 19;
            *soma = 39;
            *div = 19;
            *sub = 39;
            *Num_OPType = 4;
            break;
        
        case 4:
            *first = 2 + rand()%23;
            *mult = 22;
            *soma = 49;
            *div = 22;
            *sub = 49;
            break;
    }
}
struct DADOS op_ajustes(struct DADOS op){
    int flag = 0;
    for(int i=0; i<op.operacoes; i++){
        if(op.OP_ORDEM[0] != op.OP_ORDEM[i])
            flag = 1;
    }
    if(flag == 0){
        for(int i=0; i<op.operacoes; i++)
            op.OP_ORDEM[i] = rand()%2;
            //prinnoecho();tw("OPERACAO AJUSTADA\n");
        op_ajustes(op);
    }
    return op;
}