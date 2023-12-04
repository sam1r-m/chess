#include "king.h"
#include "board.h"
#include <iostream>

King::King(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

King::~King(){

}

bool King::isValidMove(int toX, int toY, Board *board) const{

}

char King::getChar() const{
    if (getColor() == Color::BLACK) return 'k';
    else return 'K';
}

std::vector<Move> King::generateMoves(Board *board) const{
    std::vector<Move> moves;
    return moves;
}
