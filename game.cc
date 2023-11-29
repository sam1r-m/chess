#include "game.h"
#include "piece.h"
#include <iostream>
using namespace std;

Game::Game() {

}

void Game::startGame() {
    // board.initializeBoard();
}

vector<int> Game::convert(string value) {
    // will convert the string to an array of integer of length two.
    // example: if value is a2, the function would return [1,1]
}

void Game::addPieceat(string value) {
    // uses convert to get vector
    // calls board.addPieceat() with the first and the second index
}

void Game::removePieceat(string value) {
    // uses convert to get vector
    // calls board.removePieceat() with the first and the second index
}

bool Game::makeMove(string from, string to) {
    // for move a2 a3
    // convert(from) = [1,1] and convert(to) = [1,2]
    // can pass data to makeMove in board using the necessary indexes of the two arrays above.
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
