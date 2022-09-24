#include "../include/sandbox.h"
#include "../include/unit.h"
#include "../include/graphics.h"
#include "../include/texture.h"
#include "raylib.h"
#include "../include/player.h"

void sandboxRun(void) {
    
    unitMain();
    playerMain();
    graphicsMain();

}