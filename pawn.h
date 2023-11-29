#ifndef __PAWN_H__
#define __PAWN_H__
#include <iostream>
#include "piece.h"

enum class Color { WHITE, BLACK };

class Pawn: public Piece{
    bool firstMove; // to check if pawn can move two squares

public:
    Pawn(Color col, int posX, int posY);
    ~Pawn();

    bool isValidMove(int toX, int toY) const override;
};

#endif
