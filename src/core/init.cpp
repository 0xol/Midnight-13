#include <render.hpp>
#include <main.hpp>
#include <raylib.h>
#include <stdio.h>
#include <sys/time.h>

//setup 

int main(void) {

    renderer r;
    mainLogic m;

    m.init();
    r.init();

    while (!WindowShouldClose()) {
        m.update();
        r.update();
    }

    return 0;
}