#include "game.h"

Game::Game(Board b): board {b} {}

void Game::processCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    if (cmd == "game"){
        std::string whitePlayer, blackPlayer;
        std::cin >> whitePlayer >> blackPlayer;
        startGame(whitePlayer, blackPlayer);

    } else if (cmd == "resign") {
        resign();

    } else if (cmd == "move") {
        std::string start, end;
        std::cin >> start >> end;
        movePiece(start, end);

    } else if (cmd == "setup") {


    } else {
        std::cout << "Invalid command." << std::endl;
    }
}
