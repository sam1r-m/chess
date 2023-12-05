#include "square.h"

Square::Square(int xPos, int yPos): xPos {xPos}, yPos {yPos} {}

Square::~Square(){}

int Square::getX(){
    return xPos;
}

int Square::getY(){
    return yPos;
}

Piece *Square::getPiece() const{
    return piece;
}

bool Square::isOccupied() const{
    // nullptr (false) if there is no piece, true otherwise
    return piece;
}

void Square::addPiece(Piece *p){
    piece = p;
}

void Square::attach(Observer *o) {observers.emplace_back(o);}

void Square::detachObservers() {
    observers.clear();
}

void Square::notifyObservers(){
    for (std::size_t i = 0; i < observers.size(); ++i){
	    observers[i]->notify(*this);
    } 
}
