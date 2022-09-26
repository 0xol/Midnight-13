#ifndef MENU_H
#define MENU_H

#include "raylib.h"

unsigned int mainMenu(void);

float uix(void);
float uiy(void);
Vector2 actualMousePos(void);

#define notSelected 0
#define quitGame 1
#define sandboxMode 2

#endif