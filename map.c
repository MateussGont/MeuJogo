/*
Map atributes, generation and effects
*/

#include "lib/map.h"

#define MAX_ROOMS 10
#define MIN_ROOM_SIZE 5
#define MAX_ROOM_SIZE 15

void freematriz(Mapa *map)
{
    for (int i = 0; i < map->linhas; i++)
    {
        free(map->matriz[i]);
    }
    free(map->matriz);
}
void movement(Mapa *mapa)
{
    char c = getch();
    while (c != 'p')
    {
        if (c == 'w')
        {
        }
    }
}
void imprime_mapa(Mapa *mapa)
{
    // Imprime a matriz
    for (int i = 0; i < mapa->linhas; i++)
    {
        for (int j = 0; j < mapa->colunas; j++)
        {
            mvaddch(i, j, mapa->matriz[i][j]); // Use %c para imprimir caracteres
        }
    }
}

void gera_Mapa(Mapa *mapa)
{
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    char valor = 'f';  // Valor para preencher o quadrado
    int k = 0;
    int distanciaMinimaLargura = 8;
    int distanciaMinimaAltura = 5;
    while (k < 6) // n maximo de quadrados
    {
        int largura = (rand() % 5) + 11; // numero aleatório entre 0 e 8 + 3 (entre 3 & 10)
        int altura = (rand() % 4) + 5;
        int x = rand() % (mapa->linhas - altura + 1);   // Posição x aleatória do quadrado //+1 bcauz posição inicial é 0
        int y = rand() % (mapa->colunas - largura + 1); // Posição y aleatória do quadrado

        // Verifica se o espaço está vazio e se está a uma distância mínima de outros retângulos
        bool isEmpty = true;
        for (int i = x - distanciaMinimaAltura; i < x + altura + distanciaMinimaAltura; i++)
        {
            for (int j = y - distanciaMinimaLargura; j < y + largura + distanciaMinimaLargura; j++)
            {
                if (i >= 0 && i < mapa->linhas && j >= 0 && j < mapa->colunas && mapa->matriz[i][j] == valor)
                {
                    isEmpty = false;
                    break;
                }
            }
            if (isEmpty == false)
            {
                break;
            }
        }

        // preenche mapa
        if (isEmpty == true)
        {
            for (int i = x; i < x + altura; i++)
            {
                for (int j = y; j < y + largura; j++)
                {
                    if (i == x || j == y || i == x + altura - 1 || j == y + largura - 1)
                    {
                        mapa->matriz[i][j] = '#';
                    }
                    else
                    {
                        mapa->matriz[i][j] = valor;
                    }
                }
            }
            k++;
        }
    }
    imprime_mapa(mapa);
}
void cria_Matrix(Mapa *mapa)
{
    mapa->linhas = 24;
    mapa->colunas = 80;

    mapa->matriz = malloc(mapa->linhas * sizeof(char *));

    if (mapa->matriz == NULL)
    {
        printf("Erro na alocação de memória.\n");
    }

    for (int i = 0; i < mapa->linhas; i++)
    {
        mapa->matriz[i] = malloc(mapa->colunas * sizeof(char));
        if (mapa->matriz[i] == NULL)
        {
            printf("Erro na alocação de memória.\n");
        }
    }

    // preenche a matriz
    for (int i = 0; i < mapa->linhas; i++)
    {
        for (int j = 0; j < mapa->colunas; j++)
        {
            mapa->matriz[i][j] = '.';
        }
    }

    gera_Mapa(mapa);
}