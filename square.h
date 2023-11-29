#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <vector>
#include <iostream>
#include "piece.h"

class Square {
    const int xPos;
    const int yPos;
    Piece *piece; // could use a smart pointer here to share ownership with Piece -> shared_ptr<Piece> piece;

    public:
    Square(int xPos, int yPos); // (xPos, yPos) -> Square Coordinates

    int getX();
    int getY();
    bool isOccupied();
};

std::ostream& operator<<(std::ostream &out, Square &square); // For TextDisplay

#endif
