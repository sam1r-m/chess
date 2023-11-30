#include <iostream>
#include "game.h"
#include "board.h"

int main() {
    std::unique_ptr<Board> b = std::make_unique<Board>();
    Game g(std::move(b));
    std::string command;

    while (std::getline(std::cin, command)) {
        g.processCommand(command);
    }

}
