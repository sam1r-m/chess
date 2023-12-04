#include "graphicsDisplay.h"

GraphicsDisplay::GraphicsDisplay(const std::vector<std::vector<Square>> &board)
    : boardRepresentation(board), xw(500, 500) {}

void GraphicsDisplay::drawBoard() {
    // Constants for square width and height
    const int squareSize = 50;

    for (size_t i = 0; i < boardRepresentation.size(); ++i) {
        for (size_t j = 0; j < boardRepresentation[i].size(); ++j) {
            int x = j * squareSize;
            int y = i * squareSize;

            // Alternate colors for squares
            if ((i + j) % 2 == 0) {
                xw.fillRectangle(x, y, squareSize, squareSize, Xwindow::White);
            } else {
                xw.fillRectangle(x, y, squareSize, squareSize, 2);
            }

            // Draw the piece, if any, on the square
            Piece *piece = boardRepresentation[i][j].getPiece();
            if (piece) {
                xw.drawString(x + 20, y + 30, std::string(1, piece->getChar()));
            }
        }
    }
}
