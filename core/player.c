#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include "raylib.h"
#include "../include/player.h"
#include <stdio.h>

unsigned int playerID;

unsigned int playerMaxSpeed = 100;
float acceleration = 1;

void playerInit(void) {
    playerID = getFreeUnit();
    allUnits[playerID].TYPE = PLAYER;
}

void playerMain(void) {

    if (IsKeyDown(KEY_W)) {allUnits[playerID].VECTOR.y += -1;}
    if (IsKeyDown(KEY_S)) {allUnits[playerID].VECTOR.y +=  1;}
    if (IsKeyDown(KEY_A)) {allUnits[playerID].VECTOR.x += -1;}
    if (IsKeyDown(KEY_D)) {allUnits[playerID].VECTOR.x +=  1;}
    
    camera.target.x = allUnits[playerID].VECTOR.x;
    camera.target.y = allUnits[playerID].VECTOR.y;

    printf("X:%f Y:%f\n", allUnits[playerID].VECTOR.x, allUnits[playerID].VECTOR.y);

}