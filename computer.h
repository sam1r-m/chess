#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <iostream>
#include <string>

#include "player.h"

class Computer: public Player {
    public:
    Computer(Color c, Board *board): Player(c, board) {
        humanPlayer = false;
    }
    virtual ~Computer() = default;
};

#endif
