#ifndef __QUEEN_H__
#define __QUEEN_H__
#include "piece.h"

class Queen: public Piece{

public:
    Queen(Color col, int posX, int posY);
    ~Queen();

    bool isValidMove(int toX, int toY) const override;
    char getChar() const override;
};

#endif
