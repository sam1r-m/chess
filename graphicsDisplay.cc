#include "graphicsDisplay.h"
#include "square.h"

#include <iostream>

using namespace std;

GraphicsDisplay::GraphicsDisplay(int width, int height, int boardSize): xw(width, height), boardSize(boardSize) {
    drawBoard(); // Draw empty board
}

// void GraphicsDisplay::notify(Square &s) {
//     // Update internal representation
//     int x = s.getX();
//     int y = s.getY();
//     char piece = s.isOccupied() ? s.getPiece()->getChar() : ' ';
//     theDisplay[y][x] = piece;

//     xw.fillRectangle(x, y, 500/8, 500/8);  
//     if (s.isOccupied()) {
//         xw.drawString(x, y, std::string(1, piece)); 
//     }
// }

void GraphicsDisplay::notify(Square &s) {
    drawPiece(s);  // Redraw the piece on the updated square
}

void GraphicsDisplay::drawBoard() {
    int tileSize = (500 / boardSize);
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            int color = (i + j) % 2 ? Xwindow::White : Xwindow::Black;
            xw.fillRectangle(j * tileSize, i * tileSize, tileSize, tileSize, color);
        }
    }
}

void GraphicsDisplay::drawPiece(Square &s) {
    int tileSize = 500 / boardSize;
    int x = s.getX() * tileSize;
    int y = s.getY() * tileSize;
    char piece = s.isOccupied() ? s.getPiece()->getChar() : ' ';
    if (piece != ' ') {
        xw.drawString(x + tileSize / 2, y + tileSize / 2, std::string(1, piece));
    } else {
        // Clear the square if there's no piece
        int color = (s.getX() + s.getY()) % 2 ? Xwindow::White : Xwindow::Black;
        xw.fillRectangle(x, y, tileSize, tileSize, color);
    }
}
