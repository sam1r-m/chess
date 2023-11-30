#include "game.h"



Game::Game(Board b): board {b} {}

//board must be redrawn both in text and graphically, each time a move command is issued
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
        
        if (cmd == "+") {
            std::string pieceType, posn;
            iss >> pieceType >> posn;
            addPiece(pieceType, posn);

        } else if (cmd == "-") {
            std::string posn;
            iss >> posn;
            rmPiece(posn);

        } else if (cmd == "=") {
            std::string color;
            iss >> color;
            changeTurn(color);

        } else if (cmd == "done") {

            //check that there is one king on either side, no pawns are on the
            //  first or last row, and that neitehr king is in check before leaving
            setUpMode = false;

        } else {
            std::cout << "Invalid command." << std::endl;

        }

    }

    // first command must be game or setup
    if (cmd == "game"){
        gameMode = true;
        std::string wp, bp;
        iss >> wp >> bp;
        startGame(wp, bp);

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

    gameMode = false;
}

void Game::startGame(std::string wp, std::string bp){

    //set type of whitePlayer
    if (wp == "human") whitePlayer = std::make_unique<Human>();
    else if (wp == "computer[1]") whitePlayer = std::make_unique<Computer1>();
    else if (wp == "computer[2]") whitePlayer = std::make_unique<Computer2>();
    else if (wp == "computer[3]") whitePlayer = std::make_unique<Computer3>();
    else if (wp == "computer[4]") whitePlayer = std::make_unique<Computer4>();

    //set type of blackPlayer
    if (bp == "human") blackPlayer = std::make_unique<Human>();
    else if (bp == "computer[1]") blackPlayer = std::make_unique<Computer1>();
    else if (bp == "computer[2]") blackPlayer = std::make_unique<Computer2>();
    else if (bp == "computer[3]") blackPlayer = std::make_unique<Computer3>();
    else if (bp == "computer[4]") whitePlayer = std::make_unique<Computer4>();

}
