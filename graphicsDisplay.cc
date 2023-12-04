#include "graphicsDisplay.h"

GraphicsDisplay::GraphicsDisplay(const std::vector<std::vector<Square>> &board): boardRepresentation(board), xw(500, 500) {}

void GraphicsDisplay::drawBoard() {
    int windowWidth = 500;
    int windowHeight = 500;
    int borderPadding = 30; // Adjust the padding size based on what looks best
    int tileSize = (windowWidth - 2 * borderPadding) / 8;

    // Draw squares and pieces
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int color = (i + j) % 2 == 0 ? Xwindow::White : 2;
            int x = borderPadding + j * tileSize;
            int y = borderPadding + i * tileSize;
            xw.fillRectangle(x, y, tileSize, tileSize, color);
            
            // Draw the piece (if there is one) on the square
            Piece *piece = boardRepresentation[i][j].getPiece();
            if (piece) {
                // Calculate center position for the piece text
                int pieceX = x + (tileSize / 2) - 4; // Adjust depending on text size
                int pieceY = y + (tileSize / 2) + 5; // same as above ^
                std::string pieceStr(1, piece->getChar());
                xw.drawString(pieceX, pieceY, pieceStr);
            }
        }
    }

    // Set text color for drawing coordinates
    xw.setTextColor(Xwindow::Black); // change if we want different text colors

    // Draw rank numbers (1-8) along left side of the board
    for (int i = 0; i < 8; ++i) {
        int y = borderPadding + tileSize * (i + 0.5) + 5; // center vertically
        std::string number = std::to_string(8 - i); // Reverse order for numbers (8 - 1)
        xw.drawString(borderPadding / 2 - 4, y, number); // center horizontally
    }

    // Draw file letters (a-h) along bottom of the board
    for (int j = 0; j < 8; ++j) {
        int x = borderPadding + tileSize * (j + 0.5) - 4; // center horizontally
        char letter = 'a' + j;
        std::string letterStr(1, letter);
        xw.drawString(x, windowHeight - (borderPadding / 2) + 5, letterStr); // center vertically
    }
}
