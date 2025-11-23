#include <ncurses.h>
#include <stdlib.h>
#include "calcgamelib.h"

int main(){
    initscr();
    cbreak();
    // noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int height = 10, width = 20;
    WINDOW *menuwin = newwin(10, 20, (yMax - height) / 2, (xMax - width) / 2);
    WINDOW *printwin = newwin(yMax, xMax, 0, 0);
    keypad(menuwin, true);
    refresh();

    box(menuwin, 0, 0);

    char **choices = (char**) malloc(15 * sizeof(char*));
    checkNULL(choices);
    choices[0] = "Jogar";
    choices[1] = "Como jogar";
    choices[2] = "Créditos";
    choices[3] = "Sair";


    int choice;
    int highlight = 0;

    while (true){
        for(int i = 0; i < MENU_OPTIONS; i++){
            if(i == highlight){
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i + 1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
            
        }

        choice = wgetch(menuwin);
        switch(choice){
        case KEY_UP:
            highlight--;
            if(highlight == MENU_OPTIONS - MENU_OPTIONS - 1)
                highlight = MENU_OPTIONS - MENU_OPTIONS;
            break;
        case KEY_DOWN:
            highlight++;
            if(highlight == MENU_OPTIONS)
                highlight = MENU_OPTIONS - 1;
            break;
        }
        // Pressionou Enter
        if(choice == 10){
            // Jogar
            if(highlight == 0){
                while(1){
                    //wclear(stdscr);
                    //wrefresh(stdscr);
                    suviver(4, 1);
                    refresh();
                    getchar();
                }
                getch();
                break;
            }

            // Como jogar
            if(highlight == 1){
                show_window(yMax, xMax, printwin, "comojogar.txt");
                getch();
                break;
            }
            
            // Créditos
            if(highlight == 2){
                show_window(yMax, xMax, printwin, "creditos.txt");
                getch();
                break;
            }

            // Sair
            if(highlight == 3)
                break;
        }
    }

    free(choices);
    endwin();

    return 0;
}

