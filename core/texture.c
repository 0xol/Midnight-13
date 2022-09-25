#include "raylib.h"
#include "../include/texture.h"

Texture2D PlayerTexture;
Texture2D SandTexture;

void textureInit(void) {
    PlayerTexture = LoadTexture("textures/player.png");
    SandTexture = LoadTexture("textures/sand.png");
}