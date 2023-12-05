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
        std::vector<Move> prevMoves;

    public:
        Player(Color c, Board *board);
        virtual ~Player();
        void generateAllMoves();
        virtual bool makeMove(int fromX, int fromY, int toX, int toY) = 0;
        void undoMove();
        std::vector<Move>& getMoves();
        bool isHuman();
        bool inCheck(Player *enemyPlayer);
};

#endif
