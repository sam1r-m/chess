#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>

enum class Color { WHITE, BLACK };

class Piece {
private:
    Color color;
    int x;
    int y;

public:
    Piece(Color col, int posX, int posY);
    virtual ~Piece();
    Color getColor() const;
    void setColor(Color col);
    int getX() const;
    void setX(int posX);
    int getY() const;
    void setY(int posY);

    virtual bool isValidMove(int toX, int toY) const = 0;
};

#endif
