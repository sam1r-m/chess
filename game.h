// Controller
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

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
    bool checkmate = false; //true if either player is in checkmate/loses (might change later)
    bool stalemate = false;
    std::unique_ptr<Player> whitePlayer; 
    std::unique_ptr<Player> blackPlayer;
    float whiteScore, blackScore; //stores white and black's scores
    GraphicsDisplay graphicsDisplay; // Display
    std::vector<int> convert(std::string val); //converts a textual position (e.g. "a1") to board indices
    bool startGame(std::string wp, std::string bp);
    void addPiece(std::string pieceType, std::string posn);
    void changeTurn(std::string color);
    bool validSetup();
    void endGame();

public:
    Game();

    void processCommand(const std::string& command);
    float getWScore();
    float getBScore();
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};
