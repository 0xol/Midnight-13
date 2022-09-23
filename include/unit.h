#ifndef UNIT_H
#define UNIT_H

#include "raylib.h"

#define MAX_UNITS 4096

struct UNIT {
    Vector2 VECTOR;
    float ROTATION;
    unsigned int TYPE;
    unsigned int TEAM;
};

void unitInit(void);
void unitMain(void);
unsigned int getFreeUnit(void);

#define DEAD 0
#define PLAYER 1
#define DRONE 2


extern struct UNIT allUnits[MAX_UNITS];

#endif