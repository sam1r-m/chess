#include "human.h"

Human::Human(Color c, Board *board): Player(c, board) {
    humanPlayer = true;
}

Human::~Human() {}

bool Human::makeMove(int fromX, int fromY, int toX, int toY){
    //see if Move was generated as valid
    for (std::size_t i = 0; i < playerMoves.size(); ++i){
        if(playerMoves[i].getStartX() == fromX && playerMoves[i].getStartY() == fromY
            && playerMoves[i].getEndX() == toX && playerMoves[i].getEndY() == toY){
                prevMoves.emplace_back(playerMoves[i]);

                b->makeMove(fromX, fromY, toX, toY);
                return true;
            }
    }

    std::cout << "Invalid Move." << std::endl;
    return false;
}
