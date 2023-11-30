#include <iostream>
#include "game.h"
#include "board.h"

int main() {
    Board b;
    Game g(b);
    std::string command;

    while (std::getline(std::cin, command)) {
        g.processCommand(command);
    }

}
