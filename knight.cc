#include "knight.h"
#include <iostream>

Knight::Knight(Color col, int posX, int posY): Piece {col, posX, posY} {}

Knight::~Knight(){

}

// bool Knight::isValidMove(int toX, int toY) const{
//     int deltaX = toX - getX(); // change in x
//     int deltaY = toY - getY(); // change in y
//     // L shape: so change in x is 2 y is 1 or change in x is 1 y is 2
//     bool correct = ((abs(deltaX) == 2 && abs(deltaY) == 1) || (abs(deltaX) == 1 && abs(deltaY) == 2));
//     // Check if L move made
//     if (!correct) {
//         correct = false;
//         return false;
//     }
//     // Check if within board
//     if (toX < 1 || toX > 8 || toY < 1 || toY > 8) {
//         correct = false;
//         return false;
//     }
//     // check if another piece of same team in place
//     const Board* board = getBoard();
//     // should we check if board is null?? if (!board) { cerr << "board not available" << endl; }
//     // const_cast creates a non-cast copy of destination sqaure
//     Square& destinationSquare = const_cast<Square&>(board->getSquareAt(toX, toY));
//     if (destinationSquare.isOccupied()) {
//         const Piece* pieceAtDestination = destinationSquare.getPiece();
//         auto current_colour = getColor();
//         if (pieceAtDestination->getColor() == current_colour) { // same colour
//             correct = false;
//             return false;
//         }
//     }
//     return correct;
// }

char Knight::getChar() const{
    if (getColor() == Color::BLACK) return 'n';
    else return 'N';
}

std::vector<Move> Knight::generateMoves() const{
    
}
