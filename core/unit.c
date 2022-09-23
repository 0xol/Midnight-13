#include "../include/unit.h"
#include <stdio.h>

struct UNIT allUnits[MAX_UNITS];

void unitInit(void) {
    unsigned int x = getFreeUnit();
    
    allUnits[x].TYPE = PLAYER;
    allUnits[x].ROTATION = 0;
    
}

void unitMain(void) {

}

unsigned int getFreeUnit(void) {
    for (unsigned int i = 0; i < MAX_UNITS; i++)
    {
        if (allUnits[i].TYPE == DEAD)
        {
            return i;
        }
    }
}