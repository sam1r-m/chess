#ifndef __ROOK_H__
#define __ROOK_H__
#include "piece.h"

class Rook: public Piece{
    bool firstMove; // to check if castling is possible

public:
    Rook(Color col, int posX, int posY);
    ~Rook();

    bool isValidMove(int toX, int toY) const override;
    char getChar() const override;
};

#endif
