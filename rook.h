#ifndef __ROOK_H__
#define __ROOK_H__
#include <iostream>
#include "piece.h"

enum class Color { WHITE, BLACK };

class Rook: public Piece{
    bool firstMove; // to check if castling is possible

public:
    Rook(Color col, int posX, int posY);
    ~Rook();

    bool isValidMove(int toX, int toY) const override;
};

#endif
