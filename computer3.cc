#include "computer3.h"

Computer3::Computer3(Color c, Board *board): Player(c, board) {
    humanPlayer = false;
}

Computer3::~Computer3() {}

bool Computer3::makeMove(int fromX, int fromY, int toX, int toY){
    //Level 3 Computer prefers avoiding captures, and then making captures, checks and then random moves

    // Add code for avoiding captures:
    for (std::size_t i = 0; i < playerMoves.size(); ++i){
        if (!playerMoves[i].getsCaptured()){
            b->makeMove(playerMoves[i].getStartX(), playerMoves[i].getStartY(), 
                        playerMoves[i].getEndX(), playerMoves[i].getEndY());
                        return true;
        }
    }

    // make capture move:
    for (std::size_t i = 0; i < playerMoves.size(); ++i){
        if (playerMoves[i].doesCapture()){
            b->makeMove(playerMoves[i].getStartX(), playerMoves[i].getStartY(), 
                        playerMoves[i].getEndX(), playerMoves[i].getEndY());
                        return true;
        }
    }

    // make checking move:

    //

    //if no capturing moves possible, make random move:
    if (playerMoves.empty()) {
        return false;
    }

    int length = playerMoves.size() - 1;
    srand(time(0));
    int randomIndex = (rand() % length);
    Move randomMove = playerMoves[randomIndex];

    b->makeMove(randomMove.getStartX(), randomMove.getStartY(), randomMove.getEndX(), randomMove.getEndY());
    return true;
}

