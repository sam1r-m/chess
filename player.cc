#include "player.h"
#include "board.h"
#include "piece.h"

Player::Player(Color c, Board *board): playerColor {c}, b {board} {}

Player::~Player() {}

void Player::generateAllMoves(){
    int boardSize = 8;
    playerMoves.clear();

    for (int i = 0; i < boardSize; ++i){
        for (int j = 0; j < boardSize; ++j){
            std::vector<Move> pieceMoves;

            //iterate through Board, call generateMoves on every 
            //  Piece of the same Color
            if (b->getSquareAt(i, j).isOccupied() && b->getSquareAt(i, j).getPiece()->getColor() == playerColor){
                pieceMoves = b->getSquareAt(i, j).getPiece()->generateMoves(b);

                //add Piece Moves to playerMoves vector
                for (std::size_t k = 0; k < pieceMoves.size(); k++){
                    playerMoves.emplace_back(pieceMoves[k]);  
                }   
            }
        }
    }
}


void Player::undoMove(){
    if (prevMoves.size() == 0) return;
    int startX = prevMoves[prevMoves.size() - 1].getStartX();
    int startY = prevMoves[prevMoves.size() - 1].getStartY();
    int endX = prevMoves[prevMoves.size() - 1].getEndX();
    int endY = prevMoves[prevMoves.size() - 1].getEndY();

    //Move Piece to original position
    b->makeMove(endX, endY, startX, startY);

    //If Move captured a Piece, place it back on
    //  the Board
    if (prevMoves[prevMoves.size() - 1].doesCapture()){
        b->addPieceAt(endX, endY, b->getRemovedPiece());
    }
    prevMoves.pop_back();
}

std::vector<Move>& Player::getMoves() {
    return playerMoves;
}

bool Player::isHuman(){
    return humanPlayer;
}

bool Player::inCheck(Player *enemyPlayer){
    char playerKing;
    char pieceAt;
    if (playerColor == Color::WHITE) playerKing = 'K';
    else playerKing = 'k';

    //see if enemy Player has a capturing Move on Square with Player King
    enemyPlayer->generateAllMoves();
    for (std::size_t i = 0; i < enemyPlayer->getMoves().size(); ++i){
        
        if (enemyPlayer->getMoves()[i].doesCapture()) {
            int endX = enemyPlayer->getMoves()[i].getEndX();
            int endY = enemyPlayer->getMoves()[i].getEndY();
            pieceAt = b->getSquareAt(endX - 1, 8 - endY).getPiece()->getChar();

            if (pieceAt == playerKing) {
                return true;

            }
        }               
    }
     return false;
}
