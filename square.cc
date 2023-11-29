#include "square.h"

Square::Square(int xPos, int yPos): xPos {xPos}, yPos {yPos} {}

Square::~Square(){

}

int Square::getX(){
    return xPos;
}

int Square::getY(){
    return yPos;
}

Piece *Square::getPiece(){
    return piece;
}

bool Square::isOccupied(){
    // nullptr (false) if there is no piece, true otherwise
    return piece;
}