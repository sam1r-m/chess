#include "player.h"

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

bool Player::isHuman(){
    return humanPlayer;
}
