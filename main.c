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
    
    gerar_mapa();
    getch();

    // Finaliza o ncurses
    endwin();

    return 0;
}
