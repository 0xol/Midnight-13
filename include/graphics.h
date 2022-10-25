#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <raylib.h>
#include <map.h>

void graphicsMain(void);
void graphicsInit(void);
void renderTile(struct TILE tile, unsigned int x, unsigned int y);

extern unsigned int screenWidth;
extern unsigned int screenHeight;

extern Camera2D camera;
extern Font BIOS;

#endif