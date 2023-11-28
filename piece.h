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
    Piece(Color color, int posX, int posY);
    virtual ~Piece();

    Color getColor() const;
    int getX() const;
    int getY() const;

    void setColor(Color color);
    void setX(int posX);
    void setY(int posY);

    virtual bool isValidMove(int toX, int toY) const = 0;
};

#endif
