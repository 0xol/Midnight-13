#include <build.h>
#include <map.h>
#include <raylib.h>
#include <ui.h>
#include <graphics.h>
#include <texture.h>
#include <menu.h>
#include <stdio.h>
#include <machine.h>

#define TRANSPARENT_WHITE (Color){255, 255, 255, 64}

unsigned int SelectedBuilding;
Vector2 tempPos;

void buildMain(void) {
    
    tempPos.x = (int)actualMousePos().x / 32 * 32;
    tempPos.y = (int)actualMousePos().y / 32 * 32;

    
    if (SelectedBuilding == RTG) {DrawTextureEx(RtgTexture, tempPos, 0, 2, TRANSPARENT_WHITE);}
}