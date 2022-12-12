#ifndef UNIT_H
#define UNIT_H

#include <raylib.h>

#define MAX_UNITS 8096

struct unit {
    Vector2 pos;
    unsigned short type;
    unsigned char team;
    unsigned short hp;
};

class unitHandler {
    public:
        unit allUnits[MAX_UNITS];
        void init(void);
        void update(void);
        short getFreeUnitID(void);
};

#endif