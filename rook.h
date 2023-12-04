#ifndef __ROOK_H__
#define __ROOK_H__
#include "piece.h"

class Rook: public Piece{
    mutable bool firstMove; // to check if castling is possible

public:
    Rook(Color col, int posX, int posY);
    ~Rook();

    bool isValidMove(int toX, int toY, Board *board) const override;
    char getChar() const override;
    std::vector<Move> generateMoves(Board *board) const override;
};

#endif
