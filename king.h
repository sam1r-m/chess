#ifndef __KING_H__
#define __KING_H__
#include <vector>
#include "piece.h"

class King: public Piece{
    mutable bool firstMove; //check if castling is possible

public:
    King(Color col, int posX, int posY);
    ~King();

    bool isValidMove(int toX, int toY, Board *board) const override;
    char getChar() const override;
    std::vector<Move> generateMoves(Board *board) const override;
};

#endif
