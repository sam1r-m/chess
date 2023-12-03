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
                    std::cout << "Gen" << std::endl;
                    std::cout << pieceMoves.size() << std::endl;
                //add Piece Moves to playerMoves vector
                for (int k = 0; k < pieceMoves.size(); k++){
                    playerMoves.emplace_back(pieceMoves[k]);  
                }   
            }
        }
    }
}

bool Player::isHuman(){
    return humanPlayer;
}
