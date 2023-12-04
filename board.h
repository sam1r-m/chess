// Model
#ifndef __BOARD_H__
#define __BOARD_H__

#include "square.h"
#include "textDisplay.h"
#include "graphicsDisplay.h"
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

class Piece;

class Board {
    std::vector<std::vector<Square>> board; // 2D array of Squares
    std::vector<std::unique_ptr<Piece>> pieces; // All the pieces on the board 
    const int boardSize = 8;
    std::unique_ptr<TextDisplay> td;
    std::unique_ptr<GraphicsDisplay> gd;

    public:
    Board();
    ~Board();

    void initializeBoard();
    void resetBoard();

    bool isCheck(Color color) const;
    bool isCheckmate(Color color) const;
    bool isStalemate(Color color) const; 
    // added getSquareAt(int x, int y) and getBoard() method which returns board
    const Square& getSquareAt(int x, int y) const;
    const std::vector<std::vector<Square>>& getBoard() const;
    void addPieceAt(int x, int y, std::unique_ptr<Piece> piece);
    void removePieceAt(int x, int y);

    void makeMove(int fromX, int fromY, int toX, int toY);
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
