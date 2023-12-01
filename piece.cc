#include "piece.h"
#include <iostream>
using namespace std;

Piece::Piece(Color col, int posX, int posY) : color(col), x(posX), y(posY) {}

Piece::~Piece() {}

Color Piece::getColor() const {
    return color;
}

void Piece::setColor(Color col) {
    color = col;
}

int Piece::getX() const {
    return x;
}

void Piece::setX(int posX) {
    x = posX;
}

int Piece::getY() const {
    return y;
}

void Piece::setY(int posY) {
    y = posY;
}

// isValidMove is pure virtual. Will be implemented in derived classes.

void Piece::setBoard(const Board& b) {
    boardPtr = &b;
}

const Board* Piece::getBoard() const {
    return boardPtr;
}
