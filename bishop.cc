#include "bishop.h"
#include <iostream>

Bishop::Bishop(Color col, int posX, int posY): Piece {col, posX, posY} {}

Bishop::~Bishop(){

}

bool Bishop::isValidMove(int toX, int toY, Board *board) const{

}

char Bishop::getChar() const{
    if (getColor() == Color::BLACK) return 'b';
    else return 'B';
}

std::vector<Move> Bishop::generateMoves(Board *board) const{
    std::vector<Move> moves;
    return moves;
}
