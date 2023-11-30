#include "game.h"

Game::Game(Board b): board {b} {}



void Game::processCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    // check if Game is in gameMode, only accepts resign
    //  or move commands
    if (gameMode){

        // resign gives point to opposing side
        if (cmd == "resign"){
            endGame();

        } else if (cmd == "move") {
            std::string start, end;
            iss >> start >> end;
            movePiece(start, end);

            if (checkmate) {
                endGame();
            }

        } else {
            std::cout << "Invalid command." << std::endl;
        }

    }

    // check if Game is in setUpMode, only accepts +, -, =, 
    //  and done commands
    if (setUpMode){
        

    }

    // first command must be game or setup
    if (cmd == "game"){
        gameMode = true;
        std::string whitePlayer, blackPlayer;
        iss >> whitePlayer >> blackPlayer;
        startGame(whitePlayer, blackPlayer);

    } else if (cmd == "setup") {
        setUpMode = true;

    } else {
        std::cout << "Invalid command." << std::endl;
    }
}

void Game::endGame(){
    if (blackTurn){
        whiteScore++;
    } else {
        blackScore++;
    }

    //leaves gameMode
    gameMode = false;
}
