#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include <vector>
#include "piece.h"
// #include "board.h"

class Knight: public Piece{
    // const Board* boardPtr;
public:
    Knight(Color col, int posX, int posY);
    ~Knight();

    bool isValidMove(int toX, int toY) const override;
    char getChar() const override;
    std::vector<Move> generateMoves() const override;
};

#endif
