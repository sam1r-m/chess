#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "piece.h"

class Knight: public Piece{

public:
    Knight(Color col, int posX, int posY);
    ~Knight();

    bool isValidMove(int toX, int toY) const override;
    char getChar() const override;
};

#endif
