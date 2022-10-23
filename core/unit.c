#include <unit.h>
#include <stdio.h>
#include <map.h>
#include <player.h>

struct UNIT allUnits[MAX_UNITS];

void unitInit(void) {
    
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

bool checkIfOutOfBounds(unsigned int unitId) {
    if (allUnits[unitId].VECTOR.x > MAPSIZE * 32 - 32 || allUnits[unitId].VECTOR.y > MAPSIZE * 32 - 32 || allUnits[unitId].VECTOR.x < 0 || allUnits[unitId].VECTOR.y < 0) {
        return true;        
    }
    else {
        return false;
    }
}