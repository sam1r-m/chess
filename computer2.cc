#include "computer2.h"

Computer2::Computer2(Color c, Board *board): Player(c, board) {
    humanPlayer = false;
}

Computer2::~Computer2() {}

//computer's don't need input for movement
bool Computer2::makeMove(int fromX = 0, int fromY = 0, int toX = 0, int toY= 0){
    //Level 2 Computer makes capturing moves
    for (std::size_t i = 0; i < playerMoves.size(); ++i){
        if (playerMoves[i].doesCapture()){
            b->makeMove(playerMoves[i].getStartX(), playerMoves[i].getStartY(), 
                        playerMoves[i].getEndX(), playerMoves[i].getEndY());
            prevMoves.emplace_back(playerMoves[i]);
            return true;
        }
    }

    //make checking moves
    // char enemyKing;
    // if (playerColor == Color::BLACK) enemyKing = 'K';
    // else enemyKing = 'k';

    // for (std::size_t j = 0; j < playerMoves.size(); ++j){
    //     b->makeMove(playerMoves[j].getStartX(), playerMoves[j].getStartY(), 
    //                 playerMoves[j].getEndX(), playerMoves[j].getEndY());
    //     generateAllMoves();

    //     //if next Move can capture enemy King (check), execute it
    //     for (std::size_t k = 0; k < playerMoves.size(); ++k){
    //         if (playerMoves[k].doesCapture()){
    //             int toX = playerMoves[k].getEndX();
    //             int toY = playerMoves[k].getEndY();
    //             if (b->getSquareAt(toX - 1, 8 - toY).getPiece()->getChar() == enemyKing) return true;
    //         }
    //     }
    //     undoMove();
    //     generateAllMoves();
    // }

    //if no capturing or checking moves possible, make random move:
    if (playerMoves.empty()) {
        return false;
    }

    int length = playerMoves.size() - 1;
    srand(time(0));
    int randomIndex = (rand() % length);

    Move randomMove = playerMoves[randomIndex];

    prevMoves.emplace_back(playerMoves[randomIndex]);
    b->makeMove(randomMove.getStartX(), randomMove.getStartY(), randomMove.getEndX(), randomMove.getEndY());
    return true;
}
