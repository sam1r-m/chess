#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>
#include <vector>
// #include "board.h"
#include "move.h"

enum class Color { WHITE, BLACK };
class Board;

class Piece {
protected:
    Color color;
    int x;
    int y;
    // const Board* boardPtr;
public:
    Piece(Color color, int posX, int posY);
    virtual ~Piece();

    Color getColor() const;
    int getX() const;
    int getY() const;

    void setColor(Color color);
    void setX(int posX);
    void setY(int posY);

    virtual bool isValidMove(int toX, int toY) const = 0;
    virtual char getChar() const = 0;
    
    // setBoard and getBoard added
    // void setBoard(const Board& b);
    // const Board* getBoard() const;
    // end of setBoard and getBoard

    // Pure virtual function generateMoves() added
    virtual std::vector<Move> generateMoves(Board *board) const = 0;
};

#endif
