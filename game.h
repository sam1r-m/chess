// Controller
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "board.h"
#include "player.h"
#include "human.h"
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"

class Game {
    Board board;
    bool gameMode = false;  //true if a game is ongoing
    bool setUpMode = false; //true if in setup mode
    bool blackTurn = false; //true if it is black's turn, false if it is white's
    bool checkmate = false; //true if either player is in checkmate (might change later)
    std::unique_ptr<Player> whitePlayer; 
    std::unique_ptr<Player> blackPlayer;
    int whiteScore, blackScore; //stores white and black's scores

    //make helper to convert coordinate string to ints
    //make helper to convert piece string to piece

    void startGame(std::string wp, std::string bp);
    //void movePiece(std::string start, std::string end); 
    //void addPiece(std::string pieceType, std::string posn);
    //void rmPiece(std::string posn);
    void changeTurn(std::string color);
    void endGame();

public:
    Game(Board b);

    void processCommand(const std::string& command);
};
