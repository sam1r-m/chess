// Controller
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "board.h"
#include "piece.h"
#include "player.h"
#include "graphicsDisplay.h"

class Game {
    Board board;
    bool gameMode = false;  //true if a game is ongoing
    bool setUpMode = false; //true if in setup mode
    bool blackTurn = false; //true if it is black's turn, false if it is white's
    std::unique_ptr<Player> whitePlayer;
    std::unique_ptr<Player> blackPlayer;
    float whiteScore, blackScore; //stores white and black's scores
    GraphicsDisplay graphicsDisplay; // Graphics display

    std::vector<int> convert(std::string val);  //converts a textual position (e.g. "a1") to board indices
    bool startGame(std::string wp, std::string bp); //initializes White and Black Players, returns false if either Player type is invalid
    void filterChecks(Player *currPlayer, Player *enemyPlayer); //filters out all Moves that put the current Player in check
    bool executeMove(Player *currPlayer, Player *enemyPlayer, int fromX, int fromY, int toX, int toY);  //attempts to execute Move from valid Moves
    bool isStalemate(Player *currPlayer, Player * enemyPlayer); //determines if game is in stalemate (enemy Player has no valid moves)
    void addPiece(std::string pieceType, std::string posn); //adds a Piece of type pieceType at coordinates specified by posn
    void changeTurn(std::string color); //changes it to be color's turn
    bool validSetup();  //determines if current setup is valid (one King of each color, no Pawns on front or back rank, neither Player in check)
    void endGame(); //ends game, updating score and resetting the Board

public:
    Game();

    void processCommand(const std::string& command);    //interprets specified text commands, executing them on Board
    float getWScore();  //returns White's score
    float getBScore();  //returns Black's score
};
