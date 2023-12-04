#ifndef __COMPUTER1_H__
#define __COMPUTER1_H__

#include "player.h"

class Computer1: public Player {

    public:
        Computer1(Color c, Board *board);
        ~Computer1();
        virtual bool makeMove(int fromX, int fromY, int toX, int toY) override;
};

#endif


