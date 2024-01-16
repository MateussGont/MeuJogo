/*
Map atributes, generation and effects
*/

#include "lib/map.h"

#define MAX_ROOMS 10
#define MIN_ROOM_SIZE 5
#define MAX_ROOM_SIZE 15

typedef struct
{
    int x, y, width, height;
} Room;

Room rooms[MAX_ROOMS];

// Create a new room
void newRoom(int i, char **map)
{
    Room room;
    room.width = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1);
    room.height = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1);
    room.x = rand() % (WIDTH - room.width);
    room.y = rand() % (HEIGHT - room.height);

    // Verifica a sobreposição
    bool overlap = false;
    for (int j = 0; j < i; j++)
    {
        if (rooms[j].x < room.x + room.width && rooms[j].x + rooms[j].width > room.x &&
            rooms[j].y < room.y + room.height && rooms[j].y + rooms[j].height > room.y)
        {
            overlap = true;
            break;
        }
    }

    // Se não houver sobreposição, adicione a sala ao mapa
    if (!overlap)
    {
        rooms[i] = room;
        for (int y = room.y; y < room.y + room.height; y++)
        {
            for (int x = room.x; x < room.x + room.width; x++)
            {
                map[y][x] = '#';
            }
        }
    }
}
void gerar_mapa()
{

    srand(time(NULL));

    char map[HEIGHT][WIDTH];

    // Inicializa o mapa com .
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            map[y][x] = '.';
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