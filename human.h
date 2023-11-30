#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.h"

class Human: public Player {

    public:
        Human();
        ~Human();
        void getMoves() const override;
        void makeMove() override;
};

#endif
