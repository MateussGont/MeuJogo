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
    // Desativa o eco de entrada
    noecho();
    // Habilita o teclado
    keypad(stdscr, TRUE);
    // Desativa o cursor
    curs_set(0);

    // Semeia o gerador de números aleatórios
    srand(time(NULL));

    // Inicializa o mapa
    gerar_mapa();
    // Aguarda a entrada do usuário antes de sair
    getch();

    // Finaliza o ncurses
    endwin();

    return 0;
}