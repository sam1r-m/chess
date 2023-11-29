#ifndef __KING_H__
#define __KING_H__
#include <iostream>
#include "piece.h"
using namespace std;

enum class Color { WHITE, BLACK };

class King: public Piece{
    bool firstMove; // to check if castling is possible

public:
    King(Color col, int posX, int posY);
    ~King();

    bool isValidMove(int toX, int toY) const override;
};

#endif
