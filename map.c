/*
Map atributes, generation and effects
*/

#include "ncurses.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

void gerar_mapa()
{
    // Semeia o gerador de números aleatórios
    srand(time(NULL));

    // Cria um array para o mapa
    char map[HEIGHT][WIDTH];

    // Preenche o mapa com caracteres aleatórios
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (rand() % 100 < 20)
            {
                // 20% de chance de ser um '#'
                map[y][x] = '#';
            }
            else
            {
                // 80% de chance de ser um '.'
                map[y][x] = '.';
            }
        }
    }

    // Desenha o mapa na tela
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            mvaddch(y, x, map[y][x]);
        }
    }
}