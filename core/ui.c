#include <ui.h>
#include <graphics.h>
#include <raylib.h>
#include <ui.h>
#include <texture.h>
#include <stdio.h>
#include <menu.h>
#include <machine.h>
#include <build.h>

Vector2 PowerPos;
Rectangle PowerRectangle;

#define NOTOPEN 0
#define POWER 1

Color sideMenuColour;

unsigned int isMenuOpen;

Rectangle drawBuildMenuIcon(Texture2D texture, unsigned int slot) {
    //returns Rectangle for collison detection
    
    Vector2 pos;
    Rectangle rec;

    pos.x = uix() + (screenWidth / 2) - (BUILDMENUWIDTH + SELECTMENUWIDTH);
    pos.y = uiy() - (screenHeight / 2) + (35 * slot);

    rec.x = pos.x;
    rec.y = pos.y;
    rec.width = 32;
    rec.height = 32;
    
    DrawTextureEx(texture, pos, 0, 2, WHITE);
    return rec;
}

void drawSideBuildMenu(void) {
    DrawRectangle(uix() + (screenWidth / 2) - (BUILDMENUWIDTH + SELECTMENUWIDTH), uiy() - (screenHeight / 2), SELECTMENUWIDTH, screenHeight, sideMenuColour);
}

void drawPowerMenu(void) {if (isMenuOpen == POWER) {
    drawSideBuildMenu();
    drawBuildMenuIcon(PowerTexture, 1);

    if (CheckCollisionPointRec(actualMousePos(), drawBuildMenuIcon(RtgTexture, 0)) & IsMouseButtonDown(MOUSE_BUTTON_LEFT) == true) {SelectedBuilding = RTG;}
}}

void sandboxUI(void) {
    DrawRectangle(uix() + (screenWidth / 2) - BUILDMENUWIDTH, uiy() - (screenHeight / 2), BUILDMENUWIDTH, screenHeight, BLACK);

    PowerPos.x = uix() + (screenWidth / 2) - BUILDMENUWIDTH;
    PowerPos.y = uiy() - (screenHeight / 2);
    PowerRectangle.x = uix() + (screenWidth / 2) - BUILDMENUWIDTH;
    PowerRectangle.y = PowerPos.y = uiy() - (screenHeight / 2);
    PowerRectangle.width = 32;
    PowerRectangle.height = 32;

    DrawTextureEx(PowerTexture, PowerPos, 0, 2, WHITE);

    if (CheckCollisionPointRec(actualMousePos(), PowerRectangle) & IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {isMenuOpen = POWER;}
    if (IsKeyPressed(KEY_ESCAPE) & SelectedBuilding == 0) {isMenuOpen = NOTOPEN;}
    if (IsKeyPressed(KEY_ESCAPE)) {SelectedBuilding = 0;}
    
    drawPowerMenu();
}