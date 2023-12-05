#include "bishop.h"
#include "board.h"

Bishop::Bishop(Color col, int posX, int posY): Piece {col, posX, posY} {}

Bishop::~Bishop(){}

bool Bishop::isValidMove(int toX, int toY, Board *board) const{
    //make sure Move is within Board
    if (1 > toX || toX > 8 || 1 > toY || toY > 8) return false;

    //check if Square is occupied
    if (board->getSquareAt(toX - 1, 8 - toY).isOccupied()) return false;
    
    return true;
}

char Bishop::getChar() const{
    if (getColor() == Color::BLACK) return 'b';
    else return 'B';
}

std::vector<Move> Bishop::generateMoves(Board *board) const{
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

    return moves;
}
