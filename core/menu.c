#include "raylib.h"
#include "../include/menu.h"
#include "../include/graphics.h"
#include "../include/player.h"
#include <stdio.h>
#include "../include/unit.h"

Vector2 SandboxVec;

unsigned int mainMenu(void) {

    Vector2 actualMousePos;

    actualMousePos.x = camera.offset.x - GetMousePosition().x;
    actualMousePos.y = camera.offset.y - GetMousePosition().y;

    Rectangle Sandbox;
    Sandbox.width = 200;
    Sandbox.height = 50;

    Sandbox.x = camera.target.x - (Sandbox.width / 2);
    Sandbox.y = camera.target.y - (Sandbox.height / 2);
    
    SandboxVec.x = Sandbox.x;
    SandboxVec.y = Sandbox.y;

    DrawRectangle(Sandbox.x, Sandbox.y, Sandbox.width, Sandbox.height, RED);
    DrawTextEx(BIOS, "SANDBOX", SandboxVec, 40, 0, WHITE);

    if(CheckCollisionPointRec(actualMousePos, Sandbox) & IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return sandboxMode;
    }

    return 0;
}

float uix(void) {
    float x;

    x = allUnits[playerID].VECTOR.x;
    if (IsKeyDown(KEY_A)) {x +=  1;}
    if (IsKeyDown(KEY_D)) {x += -1;}

    return x;
}

float uiy(void) {
    float y;
    
    y = allUnits[playerID].VECTOR.y;
    if (IsKeyDown(KEY_W)) {y +=  1;}
    if (IsKeyDown(KEY_S)) {y += -1;}
    return y;
}