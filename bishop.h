#ifndef __BISHOP_H__
#define __BISHOP_H__
#include "piece.h"

class Bishop: public Piece{

public:
    Bishop(Color col, int posX, int posY);
    ~Bishop();

    bool isValidMove(int toX, int toY) const override;
    char getChar() const override;
};

#endif
