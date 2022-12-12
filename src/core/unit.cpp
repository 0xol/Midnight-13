#include <unit.hpp>

void unitHandler::init(void) {

}

void unitHandler::update(void) {

}

short unitHandler::getFreeUnitID(void){
    for (short i = 0; i < MAX_UNITS - 1; i++) {if (unitHandler::allUnits[i].type == 0) {return i;}}
    return -1;
}