#include "computer2.h"

Computer2::Computer2(Color c, Board *board): Player(c, board) {
    humanPlayer = false;
}

Computer2::~Computer2() {}

bool Computer2::makeMove(int fromX, int fromY, int toX, int toY){
    //Level 2 Computer makes capturing moves:
    for (std::size_t i = 0; i < playerMoves.size(); ++i){
        if (playerMoves[i].doesCapture()){
            b->makeMove(playerMoves[i].getStartX(), playerMoves[i].getStartY(), 
                        playerMoves[i].getEndX(), playerMoves[i].getEndY());
            prevMoves.emplace_back(playerMoves[i]);
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

    prevMoves.emplace_back(playerMoves[randomIndex]);
    b->makeMove(randomMove.getStartX(), randomMove.getStartY(), randomMove.getEndX(), randomMove.getEndY());
    return true;
}
