#include "raylib.h"
#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include <stdio.h>
#include "../include/menu.h"
#include "../include/sandbox.h"
#include "../include/player.h"

unsigned int screenWidth = 1280;
unsigned int screenHeight = 720;

Camera2D camera;

int main(void) {

    printf("networking library source can be found at https://github.com/rxi/dyad/blob/master/LICENSE\n");
    printf("I <3 dyad\n");

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
    playerInit();

    SetExitKey(KEY_NULL);

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

        if (gameMode == sandboxMode) {
            sandboxRun();
        }


        EndMode2D();
        EndDrawing();
    }

    return 0;
}