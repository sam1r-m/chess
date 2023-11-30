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
    bool setUpMode = false;
    bool blackTurn = false;
    bool checkmate = false; //might change later
    std::unique_ptr<Player> whitePlayer; 
    std::unique_ptr<Player> blackPlayer; 
    int whiteScore, blackScore;

    void startGame(std::string p1, std::string p2);
    void resign();
    void movePiece(std::string start, std::string end); 
    void addPiece(std::string pieceType, std::string posn);
    void rmPiece(std::string posn);
    void endGame();

public:
    Game(Board b);

    void processCommand(const std::string& command);
};
