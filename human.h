#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.h"

class Human: public Player {

    public:
        Human(Color c, Board *board);
        ~Human();
        void makeMove() override;
};

#endif
