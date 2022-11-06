#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include "raylib.h"
#include "../include/player.h"
#include <stdio.h>
#include <map.h>
#include <menu.h>
#include <graphics.h>

unsigned int playerID;

unsigned int playerMaxSpeed = 100;
float acceleration = 1;

void playerInit(void) {
    playerID = getFreeUnit();
    allUnits[playerID].TYPE = PLAYER;

    allUnits[playerID].VECTOR.x = MAPSIZE / 2 * 32;
    allUnits[playerID].VECTOR.y = MAPSIZE / 2 * 32;
}

void playerCameraUpdate(void) {
    camera.target.x = allUnits[playerID].VECTOR.x;
    camera.target.y = allUnits[playerID].VECTOR.y;
}

void playerMain(void) {
    
    if (IsKeyDown(KEY_W)) {allUnits[playerID].VECTOR.y += -playerSpeed;}
    if (IsKeyDown(KEY_S)) {allUnits[playerID].VECTOR.y +=  playerSpeed;}
    if (IsKeyDown(KEY_A)) {allUnits[playerID].VECTOR.x += -playerSpeed;}
    if (IsKeyDown(KEY_D)) {allUnits[playerID].VECTOR.x +=  playerSpeed;}

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if ((int)actualMousePos().x / TILESIZE <= MAPSIZE & (int)actualMousePos().y / TILESIZE <= MAPSIZE)
        {
            BACKGROUND[(int)actualMousePos().x / TILESIZE][(int)actualMousePos().y / TILESIZE].TYPE = STONE;
        }
    }
    

    // print player pos
    //printf("%f %f \n", allUnits[playerID].VECTOR.x / 32, allUnits[playerID].VECTOR.y / 32);
    
    playerCameraUpdate();

    //printf("%d\n", checkIfOutOfBounds(playerID));
}