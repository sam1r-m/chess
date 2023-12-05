#ifndef __PIECE_H__
#define __PIECE_H__

#include <vector>
#include "move.h"

enum class Color { WHITE, BLACK };
class Board;

class Piece {
protected:
    Color color;    //color of Piece (White or Black)
    int x;  //x coordinate of Piece (1-8)
    int y;  //y coordinate of Piece (1-8)
    
public:
    Piece(Color color, int posX, int posY);
    virtual ~Piece();

    //Accessors
    Color getColor() const;
    int getX() const;
    int getY() const;

    void setColor(Color color);
    void setX(int posX);
    void setY(int posY);

    virtual bool isValidMove(int toX, int toY, Board *board) const = 0; //determines if Move is valid for Piece type
    virtual char getChar() const = 0;   //returns char signature of Piece based on type and color
    virtual std::vector<Move> generateMoves(Board *board) const = 0;    //generates all Moves based on Piece type
};

#endif
