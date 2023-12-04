#include "graphicsDisplay.h"
#include "square.h"

#include <iostream>

using namespace std;

GraphicsDisplay::GraphicsDisplay(int boardSize, int width, int height) 
    : xw(width, height), boardSize(boardSize), theDisplay(boardSize, std::vector<char>(boardSize, ' ')) {
    // Initial drawing of the board, etc.
    redraw();
}

void GraphicsDisplay::notify(Square &s) {
    // Update internal representation
    int x = s.getX();
    int y = s.getY();
    char piece = s.isOccupied() ? s.getPiece()->getChar() : ' ';
    theDisplay[y][x] = piece;

    xw.fillRectangle(x, y, 500/8, 500/8);  
    if (s.isOccupied()) {
        xw.drawString(x, y, std::string(1, piece)); 
    }
}

void GraphicsDisplay::redraw() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {

        }
    }
}
