#include "computer1.h"

#include<cstdlib>
#include <ctime>

Computer1::Computer1(Color c, Board *board): Player(c, board) {}
Computer1::~Computer1() {}

bool Computer1::makeMove(int fromX = 0, int fromY = 0, int toX = 0, int toY = 0) {
    if (playerMoves.empty()) {
        return false; // when there are no available moves?
    }

    int length = playerMoves.size() - 1;
    srand(time(0));
    int randomIndex = (rand() % length);

    Move randomMove = playerMoves[randomIndex];

    prevMoves.emplace_back(playerMoves[randomIndex]);
    b->makeMove(randomMove.getStartX(), randomMove.getStartY(), randomMove.getEndX(), randomMove.getEndY());
    return true;
}

