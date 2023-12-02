#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include "move.h"
#include "board.h"

class Player {
    protected:
        Color playerColor;
        Board *b;
        bool humanPlayer;
        std::vector<Move> playerMoves;

    public:
        Player(Color c, Board *board);
        virtual ~Player();
        void generateAllMoves();
        virtual void makeMove() = 0;
        bool isHuman();
};

#endif
