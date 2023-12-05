#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include "move.h"
#include "board.h"

class Player {
    protected:
        Color playerColor;  //player color (Black or White)
        Board *b;   //Player uses Board to generate Moves on Pieces of same Color
        bool humanPlayer;   
        std::vector<Move> playerMoves;  //all possible Moves
        std::vector<Move> prevMoves;    //previous Moves Player has executed

    public:
        Player(Color c, Board *board);
        virtual ~Player();  //virtual destructor
        void generateAllMoves();    //generates all possible Moves of Pieces of the same Color
        virtual bool makeMove(int fromX, int fromY, int toX, int toY) = 0;
        void undoMove();    //undoes Player's previous Move
        std::vector<Move>& getMoves();  
        bool isHuman(); //true if Player is Human, false if Computer
        bool inCheck(Player *enemyPlayer);  //returns true if Player is in check
};

#endif
