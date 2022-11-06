#include "raylib.h"
#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include "../include/player.h"
#include <stdio.h>
#include "../include/map.h"
#include <math.h>
#include "../include/menu.h"

Font BIOS;

void renderTile(struct TILE tile, unsigned int x, unsigned int y) {

    Vector2 tilePos;
    tilePos.x = x;
    tilePos.y = y;
    
    switch (tile.TYPE) {
    case SAND:
        DrawTextureEx(SandTexture, tilePos, 0, 2, WHITE);
    break;
    
    case STONE:
        DrawTextureEx(StoneTexture, tilePos, 0, 2, WHITE);
    break;
    
    default:
        
    break;
    }
}

void renderUnit(struct UNIT unit) {
    if (unit.TYPE == PLAYER)
    {
        DrawTextureEx(PlayerTexture, unit.VECTOR, unit.ROTATION, 1, RED);
    }

}

void renderAllUnits(void) {
    for (unsigned int i = 0; i < MAX_UNITS; i++) {
        if (!checkIfOutOfBounds(i))
        {
            renderUnit(allUnits[i]);
        }
        else {
            //should change to switch in future
            if (allUnits[i].VECTOR.x > MAPSIZE * 32 - 32)   {allUnits[i].VECTOR.x -= allUnits[i].VECTOR.x - (MAPSIZE * 32 - 32);}
            if (allUnits[i].VECTOR.x < 0)                   {allUnits[i].VECTOR.x = 0;}
            if (allUnits[i].VECTOR.y > MAPSIZE * 32 - 32)   {allUnits[i].VECTOR.y -= allUnits[i].VECTOR.y - (MAPSIZE * 32 - 32);}
            if (allUnits[i].VECTOR.y < 0)                   {allUnits[i].VECTOR.y = 0;}
            renderUnit(allUnits[i]);
        }
    }
    
}

void graphicsInit(void) {
    BIOS = LoadFont("textures/BIOS.ttf");
}

void playerRenderView(void) {
    for (unsigned int y = 0; y < playerViewDistance; y++)
    {
        for (unsigned int x = 0; x < playerViewDistance; x++)
        {
            unsigned int tileX = (unsigned int)(allUnits[playerID].VECTOR.x / 32) - (playerViewDistance / 2) + x;
            unsigned int tileY = (unsigned int)(allUnits[playerID].VECTOR.y / 32) - (playerViewDistance / 2) + y;

            if (tileX > MAPSIZE - 1 || tileY > MAPSIZE - 1 || tileX < 0 || tileY < 0) {
                DrawRectangle(tileX * 32, tileY * 32, 32, 32, BLACK);
            }
            else {
                renderTile(BACKGROUND[tileX][tileY], tileX * 32, tileY * 32);
            }
        }
    }
}

void graphicsMain(void) {
    playerRenderView();
    renderAllUnits();
    //DrawFPS(allUnits[playerID].VECTOR.x - (screenWidth / 2), allUnits[playerID].VECTOR.y - (screenHeight / 2));

    Vector2 pos;
    pos.x = uix() - (screenWidth / 2);
    pos.y = uiy() - (screenHeight / 2);

    DrawTextEx(BIOS, TextFormat("%i FPS\n", GetFPS()), pos, 20, 0, GREEN);
}

