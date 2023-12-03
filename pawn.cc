#include "pawn.h"
#include "board.h"
#include <iostream>

Pawn::Pawn(Color col, int posX, int posY): Piece {col, posX, posY}, firstMove {true} {}

Pawn::~Pawn(){

}

bool Pawn::isValidMove(int toX, int toY, Board *board) const{
    
}

char Pawn::getChar() const{
    if (getColor() == Color::BLACK) return 'p';
    else return 'P';
}

std::vector<Move> Pawn::generateMoves(Board *board) const{
    std::vector<Move> moves;
    int deltaX = 1;
    int deltaY;

    //Black Pawns move down, White Pawns move up
    if (color == Color::BLACK){
        if (y != 7) firstMove = false;
        deltaY = -1;
    } 
    else {
        if (y != 2) firstMove = false;
        deltaY = 1;
    }

    if (1 <= y + deltaY * 2 && y + deltaY * 2 <= 8){
        //can move 2 Square on first move, if 2 Squares ahead aren't occupied
        if (firstMove && !board->getSquareAt(x - 1, 8 - y - deltaY * 2).isOccupied() && !board->getSquareAt(x - 1, 8 - y - deltaY).isOccupied()) {
            moves.emplace_back(x, y, x, y + deltaY * 2, false);
        } 
    }

    if (1 <= y + deltaY && y + deltaY <= 8){
        //can move 1 Square foward if Square isn't occupied
        if (!board->getSquareAt(x - 1, 8 - y - deltaY).isOccupied()){
            moves.emplace_back(x, y, x, y + deltaY, false);
        }

        //check for diagonal captures
        Piece *p;
        if (x + deltaX <= 8){
            if (board->getSquareAt(x - 1 + deltaX, 8 - y - deltaY).isOccupied()){
                p = board->getSquareAt(x - 1 + deltaX, 8 - y - deltaY).getPiece();

                if (p->getColor() != color){
                    moves.emplace_back(x, y, x + deltaX, y + deltaY, true);
                }
            }
        }

        if (1 <= x - deltaX){
            if (board->getSquareAt(x - 1 - deltaX, 8 - y - deltaY).isOccupied()){
                p = board->getSquareAt(x - 1 - deltaX, 8 - y - deltaY).getPiece();

                if (p->getColor() != color){
                    moves.emplace_back(x, y, x - deltaX, y + deltaY, true);
                }
            }
        }
    }

    return moves;
}
