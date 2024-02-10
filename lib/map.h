#ifndef MAPA_H // Verifica se o identificador MAPA_H já foi definido
#define MAPA_H // Define o identificador MAPA_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct mapa
{
    char **matriz;
    int linhas, colunas;
} Mapa;

// Declaração da função
void freematriz(Mapa *map);
void imprime_mapa(Mapa *mapa);
void gera_Mapa(Mapa *mapa);
void cria_Matrix(Mapa *mapa);

#endif // Fim do bloco de definição de MAPA_H