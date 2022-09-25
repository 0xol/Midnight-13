#include "raylib.h"
#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include "../include/player.h"
#include <stdio.h>
#include "../include/map.h"
#include <math.h>

Font BIOS;

void renderTile(struct TILE tile, unsigned int x, unsigned int y) {
    
    Vector2 tilePos;
    tilePos.x = x;
    tilePos.y = y;
    
    switch (tile.TYPE) {
    case SAND:
        DrawTextureEx(SandTexture, tilePos, 0, 1, WHITE);
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
        renderUnit(allUnits[i]);
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
            
            unsigned int tileX = (unsigned int)(allUnits[playerID].VECTOR.x / 16) - (playerViewDistance / 2) + x;
            unsigned int tileY = (unsigned int)(allUnits[playerID].VECTOR.y / 16) - (playerViewDistance / 2) + y;

            renderTile(BACKGROUND[tileX][tileY], tileX * 16, tileY * 16);

        }
    }
}

void graphicsMain(void) {
    playerRenderView();
    renderAllUnits();
    DrawFPS(allUnits[playerID].VECTOR.x - (screenWidth / 2), allUnits[playerID].VECTOR.y - (screenHeight / 2));

}

