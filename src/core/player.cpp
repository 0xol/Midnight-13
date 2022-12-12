#include <render.hpp>
#include <main.hpp>
#include <player.hpp>
#include <panic.hpp>
#include <raylib.h>

void player::init(void) {
    if (u.getFreeUnitID() == -1) {panic("Unable to allocate unit ID for player");}
    player::unitID = u.getFreeUnitID();

    p.camera.offset.x = windowWidth / 2;
    p.camera.offset.y = windowHeight / 2;
    p.camera.zoom = 1;
    p.camera.target.x = 0;
    p.camera.target.y = 0;
}

void player::update(void) {
    if (IsKeyDown(KEY_W)) {u.allUnits[player::unitID].pos.x += PLAYER_MAX_SPEED;}
    if (IsKeyDown(KEY_S)) {u.allUnits[player::unitID].pos.x -= PLAYER_MAX_SPEED;}
    if (IsKeyDown(KEY_A)) {u.allUnits[player::unitID].pos.y += PLAYER_MAX_SPEED;}
    if (IsKeyDown(KEY_D)) {u.allUnits[player::unitID].pos.y -= PLAYER_MAX_SPEED;}
}