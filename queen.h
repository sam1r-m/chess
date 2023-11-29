#ifndef __QUEEN_H__
#define __QUEEN_H__
#include <iostream>
#include "piece.h"

enum class Color { WHITE, BLACK };

class Queen: public Piece{

public:
    Queen(Color col, int posX, int posY);
    ~Queen();

    bool isValidMove(int toX, int toY) const override;
};

#endif
