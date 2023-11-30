#ifndef __COMPUTER4_H__
#define __COMPUTER4_H__

#include "player.h"

class Computer4: public Player {

    public:
        Computer4();
        ~Computer4();
        void getMoves() const override;
        void makeMove() override;
};

#endif
