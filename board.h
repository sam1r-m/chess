// Model
#ifndef __BOARD_H__
#define __BOARD_H__

#include "square.h"
#include "textDisplay.h"
#include "graphicsDisplay.h"
#include "piece.h"

#include <vector>
#include <memory>
#include <iostream>

class Piece;

class Board {
    std::vector<std::vector<Square>> board; // 2D array of Squares
    std::vector<std::unique_ptr<Piece>> pieces; // All the pieces on the board 
    std::vector<std::unique_ptr<Piece>> removedPieces; // All the pieces taken from the board 
    const int boardSize = 8;
    std::unique_ptr<TextDisplay> td;

    public:
    Board();
    ~Board();

    void initializeBoard();
    void resetBoard();  //removes all Pieces from the Board

    const Square& getSquareAt(int x, int y) const;  //returns address of Square at array index x, y
    const std::vector<std::vector<Square>>& getBoard() const;   
    void addPieceAt(int x, int y, std::unique_ptr<Piece> piece);    //adds Piece on Square with coordinates x, y
    void removePieceAt(int x, int y);   //removes Piece on Square with coordinates x, y
    std::unique_ptr<Piece> getRemovedPiece();   //returns most recently removed Piece from removedPieces vector

    void makeMove(int fromX, int fromY, int toX, int toY);  //moves Piece, removing enemy Piece present at target Square
    friend std::ostream &operator<<(std::ostream &out, const Board &b); //outputs textDisplay
};

#endif
