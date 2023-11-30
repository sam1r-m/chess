#ifndef __COMPUTER2_H__
#define __COMPUTER2_H__

#include "player.h"

class Computer2: public Player {

    public:
        Computer2();
        ~Computer2();
        void getMoves() const override;
        void makeMove() override;
};

#endif
