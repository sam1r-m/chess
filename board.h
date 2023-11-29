// Model
#ifndef __BOARD_H__
#define __BOARD_H__

#include "square.h"
#include "subject.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>

enum class Color { WHITE, BLACK };

class Board: public Subject {
    std::vector<std::vector<Square>> board; // 2D array of Squares
    std::vector<std::unique_ptr<Piece>> pieces; // All the pieces on the board (maybe make it shared ptr?)

    public:
    Board();
    ~Board();

    void initializeBoard();
    void resetBoard();


    bool isCheck(Color color) const;
    bool isCheckmate(Color color) const;
    bool isStalemate(Color color) const; 

    void addPieceAt(Square *square, Color color, Piece piece);
    void removePieceAt(Square *square);

    bool makeMove(int fromX, int fromY, int toX, int toY);

};

#endif
