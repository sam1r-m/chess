#include "queen.h"
#include "board.h"

#include <iostream>
#include <cmath>

Queen::Queen(Color col, int posX, int posY): Piece {col, posX, posY} {}

Queen::~Queen(){

}

bool Queen::isValidMove(int toX, int toY, Board *board) const{
    if (toX == x && toY == y) return false; // check if its the same square

    bool isStraight = ((x == toX) || (y == toY)); // either same file or same row
    bool isDiagonal = (std::abs(y - toY) == std::abs(x - toX)); // checks that the slope is 1 (same)
    
    if (!isStraight && !isDiagonal) return false;

    int xDelta = (toX - x) > 0 ? 1 : ((toX - x) < 0 ? -1 : 0); // increment depending on position of move
    int yDelta = (toY - y) > 0 ? 1 : ((toY - y) < 0 ? -1 : 0); // same as above

    int checkPieceAtX = x + xDelta;
    int checkPieceAtY = y + yDelta;

    while ((checkPieceAtX != toX) || (checkPieceAtY != toY)) { // check each square until reached move position
        if (board->getSquareAt(checkPieceAtX, checkPieceAtY).isOccupied()) return false; // problem with BOARD POINTER
        checkPieceAtX += xDelta;
        checkPieceAtY += yDelta;
    }

    return true;
}

char Queen::getChar() const{
    if (getColor() == Color::BLACK) return 'q';
    else return 'Q';
}

std::vector<Move> Queen::generateMoves(Board *board) const{
    std::vector<Move> moves;

    for (int i = 0; i < 8; ++i) { // checks every square on the board
        for (int j = 0; j < 8; ++j) {
            bool captures = false; // Default to false

            if (board->getSquareAt(i, j).isOccupied() &&
                board->getSquareAt(i, j).getPiece()->getColor() != color) {
                captures = true; // Set to true because it is a capturing move
            }

            Move move = Move(x, y, i, j, captures);

            // Check if the queen can move to this square
            if (isValidMove(i, j, board)) {
                moves.emplace_back(move);
            }
        }
    }

    return moves;
}
