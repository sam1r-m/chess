#ifndef __COMPUTER3_H__
#define __COMPUTER3_H__

#include "player.h"

class Computer3: public Player {

    public:
        Computer3();
        ~Computer3();
        void getMoves() const override;
        void makeMove() override;
};

#endif
