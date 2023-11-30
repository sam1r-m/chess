#ifndef __COMPUTER1_H__
#define __COMPUTER1_H__

#include "player.h"

class Computer1: public Player {

    public:
        Computer1();
        ~Computer1();
        void getMoves() const override;
        void makeMove() override;
};

#endif
