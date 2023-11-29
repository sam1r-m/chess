#include "knight.h"
#include <iostream>

Knight::Knight(Color col, int posX, int posY): Piece {col, posX, posY} {}

Knight::~Knight(){

}

bool Knight::isValidMove(int toX, int toY) const{

}

char Knight::getChar() const{
    if (getColor() == Color::BLACK) return 'n';
    else return 'N';
}
