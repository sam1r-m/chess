#include "square.h"

Square::Square(int xPos, int yPos): xPos {xPos}, yPos {yPos} {}

Square::~Square(){}

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

void Square::addPiece(Piece *p){
    piece = p;
}

void Square::attach(Observer *o) {observers.emplace_back(o);}

void Square::detachObservers() {
    observers.clear();
}

void Square::notifyObservers(){
    for (int i = 0; i < observers.size(); ++i){
	    observers[i]->notify(*this);
    } 
}

std::ostream &operator<<(std::ostream &out, Square &square){

    //if square has piece, print the piece's signature
    if (square.isOccupied()) {
        out << square.piece->getChar();
    }

    //otherwise, print out the square
    else {
        int val = square.xPos + square.yPos;

        //if val is odd, square is white
        if (val % 2){
            out << " ";
        } 
        
        //otherwise, square is black
        else {
            out << "_";
        }
    }
    return out;
}
