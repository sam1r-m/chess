#ifndef __COMPUTER1_H__
#define __COMPUTER1_H__

#include "computer.h"

class Computer1: public Computer {

    public:
        Computer1(Color c, Board *board);
        ~Computer1();
        virtual bool makeMove(int fromX, int fromY, int toX, int toY) override;
};

#endif


