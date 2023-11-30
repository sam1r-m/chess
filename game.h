// Controller
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "board.h"

class Game {
    std::unique_ptr<Board> board;
    

    void startGame(std::string p1, std::string p2);
    void resign();
    void movePiece(std::string start, std::string end); //translate string to int coordinates

public:
    Game(std::unique_ptr<Board> b);

    void processCommand(const std::string& command);
};
