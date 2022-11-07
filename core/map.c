#include "../include/map.h"

struct TILE BACKGROUND[MAPSIZE][MAPSIZE];
struct TILE FOREGROUND[MAPSIZE][MAPSIZE];

void sandboxGen(void) {
    for (unsigned int y = 0; y != MAPSIZE; y++)
    {
        for (unsigned int x = 0; x != MAPSIZE; x++)
        {
            BACKGROUND[x][y].TYPE = SAND;
        }
    }
}