#include "raylib.h"
#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include <stdio.h>
#include "../include/menu.h"

unsigned int screenWidth = 1980;
unsigned int screenHeight = 1080;

Camera2D camera;

int main(void) {

    SetExitKey(KEY_NULL);

    unsigned int gameMode = 0;
    bool GameExit = false;

    camera.zoom = 1;

    camera.offset.x = screenWidth / 2;
    camera.offset.y = screenHeight / 2;

    camera.target.x = 0;
    camera.target.y = 0;

    InitWindow(screenWidth, screenHeight, "");
    SetTargetFPS(60);

    unitInit();
    textureInit();
    graphicsInit();

    while (!WindowShouldClose() & !GameExit) {
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(BLACK);
        
        if (gameMode == notSelected) {
            gameMode = mainMenu();
        }
        
        if (gameMode == quitGame)
        {
            GameExit = true;
        }

        /*
        // DO MAIN LOOPS HERE
        unitMain();
        graphicsMain();
        */

        EndMode2D();
        EndDrawing();
    }

    return 0;
}