#include <render.hpp>
#include <main.hpp>
#include <raylib.h>
#include <stdio.h>
#include <sys/time.h>

//setup 

int main(void) {

    renderer r;
    mainLogic m;

    InitWindow(500, 599, "");
    SetTargetFPS(60);

    m.update();
    r.update();

    return 0;
}