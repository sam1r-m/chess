#include <vector>
#include <string>

#include "game.h"
#include "move.h"

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include "human.h"
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"

using namespace std;

bool validCoords(int x, int y) {
    return (1 <= x) && (x <= 8) && (1 <= y) && (y <= 8);
}

Game::Game() : graphicsDisplay(board.getBoard()) { // Initialize graphicsDisplay in constructor
    board.initializeBoard();
}

//board must be redrawn both in text and graphically, each time a move command is issued
void Game::processCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    // first command must be game or setup
    if (!gameMode && !setUpMode){

        if (cmd == "game"){
            std::string wp, bp;
            iss >> wp >> bp;

            if (startGame(wp, bp)){
                gameMode = true;
                std::cout << board;
                graphicsDisplay.drawBoard();
                std::cout << "Game start." << std::endl;

            } else {
                std::cout << "Invalid player type. Expected: game (human/computer[1/2/3/4]) (human/computer[1/2/3/4])" << std::endl;
            }

            return;

        } else if (cmd == "setup") {
            setUpMode = true;
            std::cout << board;
            graphicsDisplay.drawBoard();
            std::cout << "Entering setup mode." << std::endl;
            return;

        } else {
            std::cout << "Invalid command." << std::endl;

        }

    }

    // check if Game is in gameMode, only accepts resign, undo,
    //  or move commands
    if (gameMode){

        // resign gives point to opposing side
        if (cmd == "resign"){
            endGame();

        } else if (cmd == "undo"){
            if (blackTurn){
                whitePlayer.get()->undoMove();
                blackTurn = !blackTurn;
                std::cout << board;
                graphicsDisplay.drawBoard();

            } else {
                blackPlayer.get()->undoMove();
                blackTurn = !blackTurn;
                std::cout << board;
                graphicsDisplay.drawBoard();

            }
            std::cout << "Undo previous move. ";

            if (blackTurn) {
                    cout << "Black's ";
                } else {
                    cout << "White's ";
                }
                cout << "turn again."  << endl;

        } else if (cmd == "move") {
            Player *currPlayer;
            Player *enemyPlayer;

            if (blackTurn){
                currPlayer = blackPlayer.get();
                enemyPlayer = whitePlayer.get();
            } else {
                currPlayer = whitePlayer.get();
                enemyPlayer = blackPlayer.get();
            }

                std::string start, end;
                iss >> start >> end;
                
                vector<int> from_coordinate = convert(start);
                vector<int> to_coordinate = convert(end);
                int fromX = from_coordinate[0];
                int fromY = from_coordinate[1];
                int toX = to_coordinate[0];
                int toY = to_coordinate[1];

                if (!currPlayer->isHuman() || (validCoords(fromX, fromY) && validCoords(toX, toY))){
                    if (executeMove(currPlayer, enemyPlayer, fromX, fromY, toX, toY)) blackTurn = !blackTurn;

                } else {
                    std::cout << "Invalid coordinates. Expected: move (a-h)(1-8) (a-h)(1-8)" << std::endl;
                    return;
                }

            std::cout << board;
            graphicsDisplay.drawBoard();

            if (isStalemate(currPlayer, enemyPlayer) && enemyPlayer->inCheck(currPlayer)){
                std::cout << "Checkmate! ";
                endGame();
            } else if (isStalemate(currPlayer, enemyPlayer)){
                whiteScore += 0.5;
                blackScore += 0.5;
                std::cout << "Stalemate!" << std::endl;
                board.resetBoard();
                board.initializeBoard();
                gameMode = false;
            } else if (enemyPlayer->inCheck(currPlayer)){
                if (blackTurn){
                    std::cout << "Black ";
                } else {
                    std::cout << "White ";
                }
                std::cout << "is in check." << std::endl;

            } else {

                if (blackTurn) {
                    cout << "Black's ";
                } else {
                    cout << "White's ";
                }
                cout << "turn next."  << endl;

            }

        } else {
            std::cout << "Invalid command." << std::endl;
        }

    }

    // check if Game is in setUpMode, only accepts +, -, =, 
    //  and done commands
    if (setUpMode) {
        
        if (cmd == "+") {
            std::string pieceType, posn;
            iss >> pieceType >> posn;
            addPiece(pieceType, posn);

        } else if (cmd == "-") {
            std::string posn;
            iss >> posn;

            vector<int> coordinates = convert(posn);
            int x = coordinates[0];
            int y = coordinates[1];

            if (validCoords(x, y)){
                board.removePieceAt(x,y);
                std::cout << board;
                graphicsDisplay.drawBoard();
            } else {
                std::cout << "Invalid coordinates. Expected: - (a-h)(1-8)" << std::endl;
            }

        } else if (cmd == "=") {
            std::string color;
            iss >> color;
            changeTurn(color);

        } else if (cmd == "done") {

            //check that there is one king on either side, no pawns are on the
            //  first or last row, and that neither king is in check before leaving
            if (validSetup()){
                std::cout << board;
                graphicsDisplay.drawBoard();
                std::cout << "Leaving setup mode." << std::endl;
                setUpMode = false;

            } else {
                std::cout << "Invalid setup." << std::endl;
            }

        } else {
            std::cout << "Invalid command." << std::endl;

        }

    }

}

float Game::getWScore(){
    return whiteScore;
}

float Game::getBScore(){
    return blackScore;
}

vector<int> Game::convert(std::string val) {
    std::string row = "abcdefgh";
    char base = val[1];
    int row_int[8] = {1,2,3,4,5,6,7,8};
    int index_x = row.find(val[0]);
    vector<int> cooordinate;
    int x = row_int[index_x];
    int y = base - '0';
    cooordinate.emplace_back(x);
    cooordinate.emplace_back(y);
    return cooordinate;
}

bool Game::startGame(std::string wp, std::string bp){
    bool validPlayer = true;

    //set type of whitePlayer
    if (wp == "human") whitePlayer = std::make_unique<Human>(Color::WHITE, &board);
    else if (wp == "computer1") whitePlayer = std::make_unique<Computer1>(Color::WHITE, &board);
    else if (wp == "computer2") whitePlayer = std::make_unique<Computer2>(Color::WHITE, &board);
    else if (wp == "computer3") whitePlayer = std::make_unique<Computer3>(Color::WHITE, &board);
    else if (wp == "computer4") whitePlayer = std::make_unique<Computer4>(Color::WHITE, &board);
    else validPlayer = false;

    //set type of blackPlayer
    if (bp == "human") blackPlayer = std::make_unique<Human>(Color::BLACK, &board);
    else if (bp == "computer1") blackPlayer = std::make_unique<Computer1>(Color::BLACK, &board);
    else if (bp == "computer2") blackPlayer = std::make_unique<Computer2>(Color::BLACK, &board);
    else if (bp == "computer3") blackPlayer = std::make_unique<Computer3>(Color::BLACK, &board);
    else if (bp == "computer4") whitePlayer = std::make_unique<Computer4>(Color::BLACK, &board);
    else validPlayer = false;

    return validPlayer;
}

void Game::filterChecks(Player *currPlayer, Player *enemyPlayer) {
    const auto& moves = currPlayer->getMoves();
    
    for (auto it = moves.begin(); it != moves.end();) {
        int fromX = it->getStartX();
        int fromY = it->getStartY();
        int toX = it->getEndX();
        int toY = it->getEndY();

        currPlayer->makeMove(fromX, fromY, toX, toY);

        //if the move puts Player in check, remove it from playerMoves
        if (currPlayer->inCheck(enemyPlayer)) {
            it = currPlayer->getMoves().erase(it);

        } else {
            ++it;
        }

        //undo Move after checking
        currPlayer->undoMove();
    }
}

bool Game::executeMove(Player *currPlayer, Player *enemyPlayer, int fromX, int fromY, int toX, int toY){
    currPlayer->generateAllMoves();
    filterChecks(currPlayer, enemyPlayer);
    return currPlayer->makeMove(fromX, fromY, toX, toY);
}

bool Game::isStalemate(Player *currPlayer, Player *enemyPlayer){
    enemyPlayer->generateAllMoves();
    filterChecks(enemyPlayer, currPlayer);

    //stalemate if there are no possible Moves
    return enemyPlayer->getMoves().size() == 0;
}

void Game::addPiece(string pieceType, string posn) {
    vector<int> coordinate = convert(posn);
    int x = coordinate[0];
    int y = coordinate[1];
    if (!validCoords(x, y)){
        std::cout << "Invalid coordinates. Expected: + " << pieceType << " (a-h)(1-8)" << std::endl;
        return;
    }

    std::unique_ptr<Piece> newPiece;
    
    //black pieces (lowercase)
    if (pieceType == "p") {
        newPiece = std::make_unique<Pawn>(Color::BLACK, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "k") {
        newPiece = std::make_unique<King>(Color::BLACK, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "q") {
        newPiece = std::make_unique<Queen>(Color::BLACK, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "r") {
        newPiece = std::make_unique<Rook>(Color::BLACK, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "b") {
        newPiece = std::make_unique<Bishop>(Color::BLACK, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "n") {
        newPiece = std::make_unique<Knight>(Color::BLACK, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    } 

    //white pieces (uppercase)
    else if (pieceType == "P") {
        newPiece = std::make_unique<Pawn>(Color::WHITE, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "K") {
        newPiece = std::make_unique<King>(Color::WHITE, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "Q") {
        newPiece = std::make_unique<Queen>(Color::WHITE, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "R") {
        newPiece = std::make_unique<Rook>(Color::WHITE, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "B") {
        newPiece = std::make_unique<Bishop>(Color::WHITE, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else if (pieceType == "N") {
        newPiece = std::make_unique<Knight>(Color::WHITE, x, y);
        board.addPieceAt(x, y, std::move(newPiece));
    }
    else {
        cout << pieceType << " is an invalid Piece type." << endl;
        return;
    }
    std::cout << board;
    graphicsDisplay.drawBoard();
}

void Game::changeTurn(std::string color){
    if (color == "black") {
        std::cout << "Black's turn." << std::endl;
        blackTurn = true;
    } 
    else if (color == "white") {
        std::cout << "White's turn." << std::endl;
        blackTurn = false;
    }
    else std::cout << "Invalid color. Expected: = (black/white)" << std::endl;
}

bool Game::validSetup(){
    int WKingCount = 0;
    int BKingCount = 0;

    //check for number of Kings
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){

            if (board.getSquareAt(i, j).isOccupied()){
                char piece = board.getSquareAt(i, j).getPiece()->getChar();

                //if Piece at Square is a King, add to count
                if (piece == 'K'){
                    ++WKingCount;

                } else if (piece == 'k'){
                    ++BKingCount;

                }
            }
        }
    }

    if (WKingCount != 1 || BKingCount != 1) {
        std::cout << "Incorrect number of Kings. ";
        return false;
    }
    
    //check for Pawns in last row 
    for (int k = 0; k < 8; ++k){
        if (board.getSquareAt(k, 0).isOccupied()){
            char piece = board.getSquareAt(k, 0).getPiece()->getChar();

            if (piece == 'P' || piece == 'p') {
                std::cout << "Pawn(s) in back rank. ";
                return false;
            }
        }
    }

    //check for Pawns in first row
    for (int l = 0; l < 8; ++l){
        if (board.getSquareAt(l, 7).isOccupied()){
            char piece = board.getSquareAt(l, 7).getPiece()->getChar();

            if (piece == 'P' || piece == 'p') {
                std::cout << "Pawn(s) in back rank. ";
                return false;
            }
        }
    }

    //check for check on both Kings using temporary
    //  Players to generate Moves
    whitePlayer = std::make_unique<Human>(Color::WHITE, &board);
    blackPlayer = std::make_unique<Human>(Color::BLACK, &board);
    if (whitePlayer.get()->inCheck(blackPlayer.get()) || blackPlayer.get()->inCheck(whitePlayer.get())) {
        std::cout << "A Player is in check. ";
        return false;
    }

    return true;
}

void Game::endGame(){
    if (blackTurn){
        whiteScore++;
        cout << "White wins!" << endl;
    } else {
        blackScore++;
        cout << "Black wins!" << endl;
    }

    board.resetBoard();
    board.initializeBoard();
    gameMode = false;
    blackTurn = false; 
}
