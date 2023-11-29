#include "king.h"
#include <iostream>

King::King(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

King::~King(){

}

bool King::isValidMove(int toX, int toY) const{

}
