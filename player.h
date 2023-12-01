#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include "move.h"
#include "board.h"

class Player {
    Color playerColor;
    std::vector<Move> moves;

    public:
        virtual ~Player();
        virtual void getMoves() const = 0;
        virtual void makeMove() = 0;
};

#endif
