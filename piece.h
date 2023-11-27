// PIECE.H

#ifndef PIECE_H
#define PIECE_H

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
 