#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include "raylib.h"
#include "../include/player.h"
#include <stdio.h>

unsigned int playerID;

unsigned int playerMaxSpeed = 100;
float playerSpeed;
float acceleration;

void playerInit(void) {
    playerID = getFreeUnit();
    allUnits[playerID].TYPE = PLAYER;
}

void playerMain(void) {

    if (playerSpeed < playerMaxSpeed) {
        if (IsKeyDown(KEY_W) | IsKeyDown(KEY_S) | IsKeyDown(KEY_A) | IsKeyDown(KEY_D)) {
            acceleration = playerSpeed + playerMaxSpeed / 16;
        }
    }

    if (IsKeyDown(KEY_W)) {allUnits[playerID].VECTOR.y += -acceleration;}
    if (IsKeyDown(KEY_S)) {allUnits[playerID].VECTOR.y +=  acceleration;}
    if (IsKeyDown(KEY_A)) {allUnits[playerID].VECTOR.x += -acceleration;}
    if (IsKeyDown(KEY_D)) {allUnits[playerID].VECTOR.x +=  acceleration;}

    if (playerSpeed != 0) {playerSpeed - 1;}

    camera.target.x = allUnits[playerID].VECTOR.x;
    camera.target.y = allUnits[playerID].VECTOR.y;
    
}