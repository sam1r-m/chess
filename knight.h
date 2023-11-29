#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include <iostream>
#include "piece.h"

enum class Color { WHITE, BLACK };

class Knight: public Piece{

public:
    Knight(Color col, int posX, int posY);
    ~Knight();

    bool isValidMove(int toX, int toY) const override;
};

#endif
