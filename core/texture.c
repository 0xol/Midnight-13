#include "raylib.h"
#include "../include/texture.h"

Texture2D PlayerTexture;
Texture2D SandTexture;
Texture2D PowerTexture;

void textureInit(void) {
    PlayerTexture = LoadTexture("textures/player.png");
    SandTexture = LoadTexture("textures/sand.png");
    PowerTexture = LoadTexture("textures/power.png");
}