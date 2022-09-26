#ifndef PLAYER_H
#define PLAYER_H

#define playerViewDistance 85

void playerInit(void);
void playerMain(void);
void playerCameraUpdate(void);

extern unsigned int playerID;

extern unsigned int playerMaxSpeed;

#endif