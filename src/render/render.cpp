#include <render.hpp>
#include <raylib.h>
#include <player.hpp>
#include <unit.hpp>
#include <texture.hpp>

unsigned short windowWidth;
unsigned short windowHeight;

void renderer::init(void) { 
    
    windowWidth = 1280;
    windowHeight = 720;
    
    InitWindow(windowWidth, windowHeight, "");
    SetTargetFPS(60);
}

void renderer::update(void) { 
    BeginDrawing();
    BeginMode2D(p.camera);
    ClearBackground(BLACK);

    DrawFPS(500, 500);

    renderUnits();

    EndMode2D();
    EndDrawing();
}

void renderer::renderUnits(void) {
    for (unsigned short i = 0; i < MAX_UNITS - 1; i++) {
        if (u.allUnits[i].type != 0) {
            switch (u.allUnits[i].type) {
            case PLAYER_TEXTURE:
                DrawRectangle(u.allUnits[i].pos.x, u.allUnits[i].pos.y, 20, 20, RED);
            break;
            

            }
        }
        
    }
    
}