// Model
#ifndef __BOARD_H__
#define __BOARD_H__

#include "square.h"
#include "subject.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include <vector>
#include <string>
#include <memory>
#include <iostream>

enum class Color { WHITE, BLACK };

class Board: public Subject {
    std::vector<std::vector<Square>> board; // 2D array of Squares
    std::vector<std::unique_ptr<Piece>> pieces; // All the pieces on the board (maybe make it shared ptr?)
    const int boardSize = 8;

    public:
    Board();
    ~Board();

    void initializeBoard();
    void resetBoard();

    bool isCheck(Color color) const;
    bool isCheckmate(Color color) const;
    bool isStalemate(Color color) const; 

    void addPieceAt(int x, int y, std::unique_ptr<Piece> piece);
    void removePieceAt(int x, int y);

    bool makeMove(int fromX, int fromY, int toX, int toY);

};

std::ostream &operator<<(std::ostream &out, const Board &b);

#endif
