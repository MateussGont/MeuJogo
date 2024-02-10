#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>
#include "lib/map.h"

#define WIDTH 80
#define HEIGHT 24
Mapa mapa;
int main()
{
    // Inicializa o ncurses
    initscr();
    noecho();
    // Habilita o teclado
    keypad(stdscr, TRUE);
    // Desativa o cursor
    curs_set(0);
    // Semeia o gerador de números aleatórios
    srand(time(NULL));

    cria_Matrix(&mapa);
    char tecla = getch();

    // Finaliza o ncurses
    if (tecla == 'p')
    {
        endwin();
    }
    return 0;
}
