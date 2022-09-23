#include "raylib.h"
#include "../include/menu.h"
#include "../include/graphics.h"
#include <stdio.h>

unsigned int mainMenu(void) {

    Vector2 actualMousePos;

    actualMousePos.x = camera.offset.x - GetMousePosition().x;
    actualMousePos.y = camera.offset.y - GetMousePosition().y;


    Rectangle Sandbox;
    Sandbox.width = 200;
    Sandbox.height = 50;

    Sandbox.x = camera.target.x - (Sandbox.width / 2);
    Sandbox.y = camera.target.y - (Sandbox.height / 2);

    DrawRectangle(Sandbox.x, Sandbox.y, Sandbox.width, Sandbox.height, RED);
    DrawText("Sandbox", Sandbox.x, Sandbox.y, 40, WHITE);

    if(CheckCollisionPointRec(actualMousePos, Sandbox) & IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return sandboxMode;
    }

    return 0;
}