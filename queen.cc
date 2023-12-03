#include "queen.h"
#include <iostream>

Queen::Queen(Color col, int posX, int posY): Piece {col, posX, posY} {}

Queen::~Queen(){

}

bool Queen::isValidMove(int toX, int toY, Board *board) const{

}

char Queen::getChar() const{
    if (getColor() == Color::BLACK) return 'q';
    else return 'Q';
}

std::vector<Move> Queen::generateMoves(Board *board) const{
    std::vector<Move> moves;
    return moves;
}
