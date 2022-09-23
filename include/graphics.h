#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"

void graphicsMain(void);
void graphicsInit(void);

extern unsigned int screenWidth;
extern unsigned int screenHeight;

extern Camera2D camera;

#endif