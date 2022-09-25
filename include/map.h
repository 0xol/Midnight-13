#ifndef MAP_H
#define MAP_H

#define MAPSIZE 4096

struct TILE {
    unsigned int TYPE;
};

extern struct TILE BACKGROUND[MAPSIZE][MAPSIZE];

#define ERROR 0
#define SAND 1

void sandboxGen(void);

#endif
