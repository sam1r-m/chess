#ifndef __QUEEN_H__
#define __QUEEN_H__
#include <vector>
#include "piece.h"

class Queen: public Piece{

public:
    Queen(Color col, int posX, int posY);
    ~Queen();

    bool isValidMove(int toX, int toY, Board *board) const override;
    char getChar() const override;
    std::vector<Move> generateMoves(Board *board) const override;
};

#endif
