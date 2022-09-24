#include "raylib.h"
#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include <stdio.h>

Font BIOS;

void renderUnit(struct UNIT unit) {
    if (unit.TYPE == PLAYER)
    {
        DrawTextureEx(PlayerTexture, unit.VECTOR, unit.ROTATION, 1, RED);
    }

}

void renderAllUnits(void) {
    for (unsigned int i = 0; i <= MAX_UNITS - 1; i++)
    {
        renderUnit(allUnits[i]);
    }
    
}

void graphicsInit(void) {
    BIOS = LoadFont("textures/BIOS.ttf");
}

void graphicsMain(void) {
    renderAllUnits();
}

