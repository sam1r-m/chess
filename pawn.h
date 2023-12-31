#ifndef __PAWN_H__
#define __PAWN_H__
#include <vector>
#include "piece.h"

class Pawn: public Piece{
    mutable bool firstMove; // to check if pawn can move two squares

public:
    Pawn(Color col, int posX, int posY);
    ~Pawn();

    bool isValidMove(int toX, int toY, Board *board) const override;
    char getChar() const override;
    std::vector<Move> generateMoves(Board *board) const override;
};

#endif
