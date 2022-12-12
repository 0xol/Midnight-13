#include <render.hpp>
#include <raylib.h>
#include <player.hpp>

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

    DrawText("sus", 500, 500, 10, RED);

    EndMode2D();
    EndDrawing();
}