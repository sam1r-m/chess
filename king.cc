#include "king.h"
#include "board.h"
#include <cmath>

King::King(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

King::~King() {}

bool King::isValidMove(int toX, int toY, Board *board) const{
    // Ensure the destniation coordinates are within the board
    if (toX < 1 || toX > 8 || toY < 1 || toY > 8) return false;

    // Check that the move is within one square in any direction
    if (std::abs(toX - x) > 1 || std::abs(toY - y) > 1) return false;

    // Ensure the destination square is not occupied by a piece of the same color
    if (board->getSquareAt(toX - 1, 8 - toY).isOccupied() &&
        board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() == this->color) {
        return false;
    }

    // >> add code for checks and castling here <<

    return true;
}

char King::getChar() const{
    if (getColor() == Color::BLACK) return 'k';
    else return 'K';
}

std::vector<Move> King::generateMoves(Board *board) const{
    std::vector<Move> moves;

    //check if King has moved yet
    if (color == Color::BLACK){
        if (y != 8 || x != 5) firstMove = false;
    } 
    else {
        if (y != 1 || x != 5) firstMove = false;
    }

    // One square in every direction
    for (int deltaX = -1; deltaX <= 1; ++deltaX) {
        for (int deltaY = -1; deltaY <= 1; ++deltaY) {
            if (deltaX == 0 && deltaY == 0) continue; // skip current square

            int toX = x + deltaX;
            int toY = y + deltaY;

            if (isValidMove(toX, toY, board)) {
                bool captures = board->getSquareAt(toX - 1, 8 - toY).isOccupied();
                moves.emplace_back(x, y, toX, toY, captures);
            }
        }
    }

    return moves;
}
