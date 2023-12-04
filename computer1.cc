#include "computer1.h"

#include<cstdlib>
#include <ctime>

Computer1::Computer1(Color c, Board *board): Computer(c, board) {}
Computer1::~Computer1() {}

bool Computer1::makeMove(int fromX, int fromY, int toX, int toY) {
    if (playerMoves.empty()) {
        return false; // when there are no available moves?
    }

    int length = playerMoves.size() - 1;
    srand(time(0));
    int randomIndex = (rand() % length);

    Move randomMove = playerMoves[randomIndex];

    b->makeMove(randomMove.getStartX(), randomMove.getStartY(), randomMove.getEndX(), randomMove.getEndY());
    return true;
}

