#ifndef __COMPUTER4_H__
#define __COMPUTER4_H__

#include "player.h"

class Computer4: public Player {

    public:
        Computer4(Color c, Board *board);
        ~Computer4();
        void makeMove() override;
};

#endif
