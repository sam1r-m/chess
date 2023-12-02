#include "player.h"

Player::Player(Color c, Board *board): playerColor {c}, b {board} {}

Player::~Player() {}

void Player::generateAllMoves(){
    int boardSize = 8;

    for (int i = 0; i < boardSize; ++i){
        for (int j = 0; j < boardSize; ++j){
            //iterate through Board, call generateMoves on every 
            //  Piece of the same Color

        }
    }
}
