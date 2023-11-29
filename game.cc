#include "game.h"
#include "piece.h"
#include <iostream>
using namespace std;

Game::Game() {

}

void Game::startGame() {
    // board.initializeBoard();
}

bool Game::makeMove(int fromX, int fromY, int toX, int toY) {
    
}

bool Game::isCheckmate(Color color) const {
    // return board.isCheckmate(color);
}

bool Game::isStalemate(Color color) const {
    // return board.isStalemate(color);
}

void Game::switchTurn() {
    // isWhiteTurn = !isWhiteTurn;
}
