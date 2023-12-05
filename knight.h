#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include <vector>
#include "piece.h"

class Knight: public Piece{
public:
    Knight(Color col, int posX, int posY);
    ~Knight();

    bool isValidMove(int toX, int toY, Board *board) const override;
    char getChar() const override;
    std::vector<Move> generateMoves(Board *board) const override;
};

#endif
