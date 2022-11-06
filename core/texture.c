#include <raylib.h>
#include <texture.h>
#include <ui.h>

Texture2D PlayerTexture;
Texture2D SandTexture;
Texture2D PowerTexture;
Texture2D StoneTexture;
Texture2D RtgTexture;

void textureInit(void) {
    PlayerTexture = LoadTexture("textures/player.png");
    SandTexture = LoadTexture("textures/sand.png");
    PowerTexture = LoadTexture("textures/power.png");
    StoneTexture = LoadTexture("textures/stone.png");
    RtgTexture = LoadTexture("textures/rtg.png");

    sideMenuColour.r = 80;
    sideMenuColour.g = 105;
    sideMenuColour.b = 105;
    sideMenuColour.a = 255;
}