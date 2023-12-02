#include "pawn.h"
#include <iostream>

Pawn::Pawn(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

Pawn::~Pawn(){

}

bool Pawn::isValidMove(int toX, int toY) const{

}

char Pawn::getChar() const{
    if (getColor() == Color::BLACK) return 'p';
    else return 'P';
}

std::vector<Move> Pawn::generateMoves(Board *board) const{
    
}
