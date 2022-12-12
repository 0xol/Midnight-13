#include <main.hpp>
#include <unit.hpp>
#include <panic.hpp>
#include <player.hpp>

#include <stdio.h>

unitHandler u;
player p;

void mainLogic::init(void) {
    p.init();
}

void mainLogic::update(void) {
    p.update();
}