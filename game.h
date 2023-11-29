// Controller
#ifndef __GAME_H__
#define __GAME_H__

#include "board.h"
#include "piece.h"

#include <vector>
#include <string>
#include <memory>
#include <iostream>

enum class Color { WHITE, BLACK };

class Game {
private:
    Board board;
    bool isWhiteTurn;

public:
    Game();
    void startGame();
    bool makeMove(int fromX, int fromY, int toX, int toY);
    bool isCheckmate(Color color) const; 
    bool isStalemate(Color color) const; 
    void switchTurn();
};

#endif
