#include "queen.h"
#include "board.h"

#include <iostream>
#include <cmath>

Queen::Queen(Color col, int posX, int posY): Piece {col, posX, posY} {}

Queen::~Queen(){

}

bool Queen::isValidMove(int toX, int toY, Board *board) const{
    // if (toX == x && toY == y) return false; // check if its the same square

    // bool isStraight = ((x == toX) || (y == toY)); // either same file or same row
    // bool isDiagonal = (std::abs(y - toY) == std::abs(x - toX)); // checks that the slope is 1 (same)
    
    // if (!isStraight && !isDiagonal) return false;

    // int xDelta = (toX - x) > 0 ? 1 : ((toX - x) < 0 ? -1 : 0); // increment depending on position of move
    // int yDelta = (toY - y) > 0 ? 1 : ((toY - y) < 0 ? -1 : 0); // same as above

    // int checkPieceAtX = x + xDelta;
    // int checkPieceAtY = y + yDelta;

    // while ((checkPieceAtX != toX) || (checkPieceAtY != toY)) { // check each square until reached move position
    //     if (board->getSquareAt(checkPieceAtX, checkPieceAtY).isOccupied()) return false; // problem with BOARD POINTER
    //     checkPieceAtX += xDelta;
    //     checkPieceAtY += yDelta;
    // }

    // return true;

    //make sure Move is within Board
    if (1 > toX || toX > 8 || 1 > toY || toY > 8) return false;

    //check if Square is occupied
    if (board->getSquareAt(toX - 1, 8 - toY).isOccupied()) return false;
    
    return true;
}

char Queen::getChar() const{
    if (getColor() == Color::BLACK) return 'q';
    else return 'Q';
}

std::vector<Move> Queen::generateMoves(Board *board) const{
    // std::vector<Move> moves;

    // for (int i = 0; i < 8; ++i) { // checks every square on the board
    //     for (int j = 0; j < 8; ++j) {
    //         bool captures = false; // Default to false

    //         if (board->getSquareAt(i, j).isOccupied() &&
    //             board->getSquareAt(i, j).getPiece()->getColor() != color) {
    //             captures = true; // Set to true because it is a capturing move
    //         }

    //         Move move = Move(x, y, i, j, captures);

    //         // Check if the queen can move to this square
    //         if (isValidMove(i, j, board)) {
    //             moves.emplace_back(move);
    //         }
    //     }
    // }

    // return moves;
    
    std::vector<Move> moves;
    int deltaX = 1;
    int deltaY = 1;
    int toX, toY;

    //generate Moves in top right direction
    for (int i = 1; i < 8; ++i){
        toX = x + deltaX * i;
        toY = y + deltaY * i;
       
        if (isValidMove(toX, toY, board)) {
            moves.emplace_back(x, y, toX, toY, false);
        } else {

            //if Move was filtered out due to Square being occupied, check
            //  if Piece is of other Color 
            if (1 <= toX && toX <= 8 && 1 <= toY && toY <= 8){
                if (board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() != color){ 
                    moves.emplace_back(x, y, toX, toY, true);
                }
                break;
            }
        }
    }

    //generate Moves in bottom right direction
    for (int i = 1; i < 8; ++i){
        toX = x + deltaX * i;
        toY = y - deltaY * i;

        if (isValidMove(toX, toY, board)) {
            moves.emplace_back(x, y, toX, toY, false);
        } else {

            //if Move was filtered out due to Square being occupied, check
            //  if Piece is of other Color 
            if (1 <= toX && toX <= 8 && 1 <= toY && toY <= 8){
                if (board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() != color){
                    moves.emplace_back(x, y, toX, toY, true);
                }
                break;
            }
        }
    }

    //generate Moves in bottom left direction
    for (int i = 1; i < 8; ++i){
        toX = x - deltaX * i;
        toY = y - deltaY * i;

        if (isValidMove(toX, toY, board)) {
            moves.emplace_back(x, y, toX, toY, false);
        } else {

            //if Move was filtered out due to Square being occupied, check
            //  if Piece is of other Color 
            if (1 <= toX && toX <= 8 && 1 <= toY && toY <= 8){
                if (board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() != color){
                    moves.emplace_back(x, y, toX, toY, true);
                }
                break;
            }
        }
    }

    //generate Moves in top left direction
    for (int i = 1; i < 8; ++i){
        toX = x - deltaX * i;
        toY = y + deltaY * i;

        if (isValidMove(toX, toY, board)) {
            moves.emplace_back(x, y, toX, toY, false);
        } else {

            //if Move was filtered out due to Square being occupied, check
            //  if Piece is of other Color 
            if (1 <= toX && toX <= 8 && 1 <= toY && toY <= 8){
                if (board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() != color){
                    moves.emplace_back(x, y, toX, toY, true);
                }
                break;
            }
        }
    }

    //generate rightward Moves
    for (int i = 1; i < 8; ++i){
        toX = x + deltaX * i;
        toY = y;
       
        if (isValidMove(toX, toY, board)) {
            moves.emplace_back(x, y, toX, toY, false);
        } else {

            //if Move was filtered out due to Square being occupied, check
            //  if Piece is of other Color 
            if (1 <= toX && toX <= 8 && 1 <= toY && toY <= 8){
                if (board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() != color){ 
                    moves.emplace_back(x, y, toX, toY, true);
                }
                break;
            }
        }
    }

    //generate upwards Moves
    for (int i = 1; i < 8; ++i){
        toX = x;
        toY = y + deltaY * i;

        if (isValidMove(toX, toY, board)) {
            moves.emplace_back(x, y, toX, toY, false);
        } else {

            //if Move was filtered out due to Square being occupied, check
            //  if Piece is of other Color 
            if (1 <= toX && toX <= 8 && 1 <= toY && toY <= 8){
                if (board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() != color){
                    moves.emplace_back(x, y, toX, toY, true);
                }
                break;
            }
        }
    }

    //generate leftward Moves
    for (int i = 1; i < 8; ++i){
        toX = x - deltaX * i;
        toY = y;
       
        if (isValidMove(toX, toY, board)) {
            moves.emplace_back(x, y, toX, toY, false);
        } else {

            //if Move was filtered out due to Square being occupied, check
            //  if Piece is of other Color 
            if (1 <= toX && toX <= 8 && 1 <= toY && toY <= 8){
                if (board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() != color){ 
                    moves.emplace_back(x, y, toX, toY, true);
                }
                break;
            }
        }
    }

    //generate downward Moves
    for (int i = 1; i < 8; ++i){
        toX = x;
        toY = y - deltaY * i;

        if (isValidMove(toX, toY, board)) {
            moves.emplace_back(x, y, toX, toY, false);
        } else {

            //if Move was filtered out due to Square being occupied, check
            //  if Piece is of other Color 
            if (1 <= toX && toX <= 8 && 1 <= toY && toY <= 8){
                if (board->getSquareAt(toX - 1, 8 - toY).getPiece()->getColor() != color){
                    moves.emplace_back(x, y, toX, toY, true);
                }
                break;
            }
        }
    }

    return moves;
}
