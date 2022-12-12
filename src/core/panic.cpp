#include <string>
#include <raylib.h>
#include <iostream>

void panic(std::string error_message) {
    std::cout << error_message;
    CloseWindow();
}