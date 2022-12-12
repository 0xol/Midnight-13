#include <render.hpp>
#include <raylib.h>

void renderer::init(void) { 
    InitWindow(500, 500, "");
    SetTargetFPS(60);
}

void renderer::update(void) { 
    BeginDrawing();

    EndDrawing();
}