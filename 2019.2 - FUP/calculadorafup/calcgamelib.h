#ifndef CALCGAMELIB_H
#define CALCGAMELIB_H

#include <ncurses.h>

#define checkNULL(n) if(!n){ fprintf(stderr, "Erro ao alocar memória ou abrir arquivo\n"); return 1;}
#define MENU_OPTIONS 4

struct DADOS{
    int movimentos;
    int operacoes;
    int OP_NUMEROS[8];
    int OP_ORDEM[8];
    int RESULTADO;
};

void CONSTANTES(int nivel, int *mult, int  *soma, int *div, int *sub, int *first, int*, int);
void gerador(struct DADOS);
void gerador(struct DADOS play);
struct DADOS suviver(int Movimentos, int nivel);
struct DADOS op_ajustes(struct DADOS op);

int show_window(int yMax, int xMax, WINDOW *printwin, const char *filename);

#endif