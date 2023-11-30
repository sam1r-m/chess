// Controller
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "board.h"
#include "player.h"

class Game {
    Board board;
    bool gameMode = false;
    bool setupMode = false;
    bool blackTurn = false;


    void startGame(std::string p1, std::string p2);
    void resign();
    void movePiece(std::string start, std::string end); //translate string to int coordinates

public:
    Game(Board b);

    void processCommand(const std::string& command);
};
