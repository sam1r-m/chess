#include "king.h"
#include <iostream>
using namespace std;

King::King(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

King::~King(){

}

bool King::isValidMove(int toX, int toY) const{

}
