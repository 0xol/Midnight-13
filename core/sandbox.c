#include "../include/sandbox.h"
#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include "raylib.h"
#include "../include/player.h"
#include "../include/map.h"

int genDone = 0;

void sandboxRun(void) {
    
    if (genDone == 0) {
        sandboxGen();
        genDone = 1;
    }
    

    unitMain();
    playerMain();
    graphicsMain();

}