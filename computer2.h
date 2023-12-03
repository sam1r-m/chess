#ifndef __COMPUTER2_H__
#define __COMPUTER2_H__

#include "player.h"

class Computer2: public Player {

    public:
        Computer2(Color c, Board *board);
        ~Computer2();
        bool makeMove(int fromX, int fromY, int toX, int toY) override;
};

#endif
