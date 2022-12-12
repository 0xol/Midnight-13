#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

#define PLAYER_MAX_SPEED 10

class player {
    public:
        unsigned short unitID;
        Camera2D camera;
        void init(void);
        void update(void);
        
};

extern player p;

#endif