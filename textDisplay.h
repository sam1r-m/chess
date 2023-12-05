// View
#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <vector>
#include <iostream>
#include "observer.h"
class Square;

class TextDisplay: public Observer {
    std::vector<std::vector<char>> theDisplay;
    const int boardSize = 8;
    
    public:
    TextDisplay();
    ~TextDisplay();

    void addPiece(int x, int y, char piece);    //helper to add Piece chars to Display
    void notify(Square &s) override;    //updates char to Piece or Square char
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);  //outputs textDisplay with coordinate indices along sides
};

#endif
