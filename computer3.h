#ifndef __COMPUTER3_H__
#define __COMPUTER3_H__

#include "player.h"

class Computer3: public Player {

    public:
        Computer3(Color c, Board *board);
        ~Computer3();
        void makeMove() override;
};

#endif
