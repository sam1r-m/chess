#ifndef __COMPUTER2_H__
#define __COMPUTER2_H__

#include "player.h"

class Computer2: public Player {

    public:
        Computer2(Color c, Board *board);
        ~Computer2();
        void makeMove() override;
};

#endif
