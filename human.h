#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.h"

class Human: public Player {

    public:
        Human(Color c, Board *board);
        ~Human();
        virtual bool makeMove(int fromX, int fromY, int toX, int toY) override; //attempts to make Move based on user input
};

#endif
