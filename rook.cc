#include "rook.h"
#include <iostream>

Rook::Rook(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

Rook::~Rook(){

}

bool Rook::isValidMove(int toX, int toY) const{

}

char Rook::getChar() const{
    if (getColor() == Color::BLACK) return 'r';
    else return 'R';
}

std::vector<Move> Rook::generateMoves() const{
    
}
