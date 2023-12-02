#include "pawn.h"
#include <iostream>

Pawn::Pawn(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

Pawn::~Pawn(){

}

bool Pawn::isValidMove(int toX, int toY, Board *board) const{
    
}

char Pawn::getChar() const{
    if (getColor() == Color::BLACK) return 'p';
    else return 'P';
}

std::vector<Move> Pawn::generateMoves(Board *board) const{
    int deltaX = 1;
    int deltaY;

    //Black Pawns move down, White Pawns move up
    if (color == Color::BLACK) deltaY = -1;
    else deltaY = 1;

    if (firstMove){

    }
}
