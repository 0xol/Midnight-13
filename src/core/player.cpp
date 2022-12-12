#include <render.hpp>
#include <main.hpp>
#include <player.hpp>
#include <panic.hpp>
#include <raylib.h>
#include <texture.hpp>

void player::init(void) {
    if (u.getFreeUnitID() == -1) {panic("Unable to allocate unit ID for player");}
    player::unitID = u.getFreeUnitID();

    u.allUnits[player::unitID].type = PLAYER_TEXTURE;

    player::camera.offset.x = windowWidth / 2;
    player::camera.offset.y = windowHeight / 2;
    player::camera.zoom = 1;
    player::camera.target.x = windowWidth / 2;
    player::camera.target.y = windowHeight / 2;

    
}

void player::update(void) {
    if (IsKeyDown(KEY_W)) {u.allUnits[player::unitID].pos.y -= PLAYER_MAX_SPEED;}
    if (IsKeyDown(KEY_S)) {u.allUnits[player::unitID].pos.y += PLAYER_MAX_SPEED;}
    if (IsKeyDown(KEY_A)) {u.allUnits[player::unitID].pos.x -= PLAYER_MAX_SPEED;}
    if (IsKeyDown(KEY_D)) {u.allUnits[player::unitID].pos.x += PLAYER_MAX_SPEED;}

    player::camera.target = u.allUnits[player::unitID].pos;

}