#ifndef __BISHOP_H__
#define __BISHOP_H__
#include <iostream>
#include "piece.h"

enum class Color { WHITE, BLACK };

class Bishop: public Piece{

public:
    Bishop(Color col, int posX, int posY);
    ~Bishop();

    bool isValidMove(int toX, int toY) const override;
};

#endif
