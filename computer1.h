#ifndef __COMPUTER1_H__
#define __COMPUTER1_H__

#include "computer.h"

class Computer1: public Computer {

    public:
        Computer1(Color c, Board *board);
        ~Computer1();
        virtual void makeMove() override;
};

#endif


