#ifndef __BISHOP_H__
#define __BISHOP_H__
#include <vector>
#include "piece.h"

class Bishop: public Piece{

public:
    Bishop(Color col, int posX, int posY);
    ~Bishop();

    bool isValidMove(int toX, int toY) const override;
    char getChar() const override;
    std::vector<Move> generateMoves() const override;
};

#endif
