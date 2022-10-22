#include <ui.h>
#include <graphics.h>
#include <raylib.h>
#include <menu.h>
#include <texture.h>
#include <stdio.h>

Vector2 PowerPos;
Rectangle PowerRectangle;
    

void sandboxUI(void) {
    DrawRectangle(uix() + (screenWidth / 2) - BUILDMENUWIDTH, uiy() - (screenHeight / 2), BUILDMENUWIDTH, screenHeight, BLACK);
    
    PowerPos.x = uix() + (screenWidth / 2) - BUILDMENUWIDTH;
    PowerPos.y = uiy() - (screenHeight / 2);
    PowerRectangle.x = uix() + (screenWidth / 2) - BUILDMENUWIDTH;
    PowerRectangle.y = PowerPos.y = uiy() - (screenHeight / 2);
    PowerRectangle.width = 32;
    PowerRectangle.height = 32;

    DrawTextureEx(PowerTexture, PowerPos, 0, 2, WHITE);

    if (CheckCollisionPointRec(actualMousePos(), PowerRectangle) & IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        printf("troll");
    }
    
    

}