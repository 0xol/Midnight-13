#include <ui.h>
#include <graphics.h>
#include <raylib.h>
#include <menu.h>
#include <texture.h>
#include <stdio.h>

Vector2 PowerPos;
Rectangle PowerRectangle;

#define NOTOPEN 0
#define POWER 1

Color sideMenuColour;

unsigned int isMenuOpen;

void drawSideBuildMenu(void) {
    DrawRectangle(uix() + (screenWidth / 2) - (BUILDMENUWIDTH + SELECTMENUWIDTH), uiy() - (screenHeight / 2), SELECTMENUWIDTH, screenHeight, sideMenuColour);
}

void drawPowerMenu(void) {if (isMenuOpen == POWER) {
    drawSideBuildMenu();
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

    if (CheckCollisionPointRec(actualMousePos(), PowerRectangle) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {isMenuOpen = POWER;}
    if (IsKeyPressed(KEY_ESCAPE)) {isMenuOpen = NOTOPEN;}
    
    drawPowerMenu();
}