#include "bishop.h"
#include <iostream>
using namespace std;

Bishop::Bishop(Color col, int posX, int posY): Piece {col, posX, posY} {}

Bishop::~Bishop(){

}

bool Bishop::isValidMove(int toX, int toY) const{

}
