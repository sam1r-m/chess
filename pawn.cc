#include "pawn.h"
#include <iostream>

Pawn::Pawn(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

Pawn::~Pawn(){

}

bool Pawn::isValidMove(int toX, int toY) const{

}
