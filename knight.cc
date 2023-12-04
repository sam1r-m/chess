#include "knight.h"
#include "board.h"
#include <iostream>

Knight::Knight(Color col, int posX, int posY): Piece {col, posX, posY} {}

Knight::~Knight(){

}

bool Knight::isValidMove(int toX, int toY, Board *board) const{
    int deltaX = toX - getX(); // change in x
    int deltaY = toY - getY(); // change in y
    // L shape: so change in x is 2 y is 1 or change in x is 1 y is 2
    bool correct = ((abs(deltaX) == 2 && abs(deltaY) == 1) || (abs(deltaX) == 1 && abs(deltaY) == 2));
    // Check if L move made
    if (!correct) {
        correct = false; //
        return false;
    }
    // Check if within board
    if (toX < 1 || toX > 8 || toY < 1 || toY > 8) {
        correct = false;
        return false;
    }
    // check if another piece of same team in place
    if (board->getSquareAt(toX, toY).isOccupied() && board->getSquareAt(toX, toY).getPiece()->getColor() == getColor()) {
        return false;
    }
    return correct;
}

char Knight::getChar() const{
    if (getColor() == Color::BLACK) return 'n';
    else return 'N';
}

std::vector<Move> Knight::generateMoves(Board *board) const {
    std::vector<Move> possibleMoves;

    std::vector<std::pair<int, int>> knightMoves = {{2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}};

    for (const auto &move : knightMoves) {
        int toX = getX() + move.first;
        int toY = getY() + move.second;

        if (isValidMove(toX, toY, board)) {
            possibleMoves.emplace_back(getX(), getY(), toX, toY, false);
        }
    }

    return possibleMoves;
}

