#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include "move.h"
#include "board.h"

class Player {
    Color playerColor;
    Board *b;
    std::vector<Move> playerMoves;
    protected:
        bool humanPlayer;

    public:
        Player(Color c, Board *board);
        virtual ~Player();
        void generateAllMoves();
        virtual void makeMove() = 0;
        bool isHuman();
};

#endif
