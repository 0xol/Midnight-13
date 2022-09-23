#include "raylib.h"
#include "../include/texture.h"

Texture2D PlayerTexture;

void textureInit(void) {
    PlayerTexture = LoadTexture("textures/player.png");
}