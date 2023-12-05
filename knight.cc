#include "knight.h"
#include "board.h"

Knight::Knight(Color col, int posX, int posY): Piece {col, posX, posY} {}

Knight::~Knight(){

}

bool Knight::isValidMove(int toX, int toY, Board *board) const{
    int deltaX = toX - getX(); // change in x
    int deltaY = toY - getY(); // change in y

    // L shape, change in x is 2, y is 1 or change in x is 1, y is 2
    bool correct = ((abs(deltaX) == 2 && abs(deltaY) == 1) || (abs(deltaX) == 1 && abs(deltaY) == 2));

    // Check if L move made
    if (!correct) {
        return false;
    }

    // Check if within board
    if (toX < 1 || toX > 8 || toY < 1 || toY > 8) {
        return false;
    }

    const Square& destinationSquare = board->getSquareAt(toX - 1, 8 - toY);
    if (destinationSquare.isOccupied()) {
        
        const Piece* pieceAtDestination = destinationSquare.getPiece();
        if (pieceAtDestination->getColor() == getColor()) { // same colour
            return false;
        }
    }

    return correct;
}

char Knight::getChar() const{
    if (getColor() == Color::BLACK) return 'n';
    else return 'N';
}

std::vector<Move> Knight::generateMoves(Board *board) const{
    std::vector<Move> moves;
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            if (isValidMove(i, j, board)) {
                moves.emplace_back(x, y, i, j, board->getSquareAt(i - 1, 8 - j).isOccupied());
            }
        }
    }
    return moves;
}
