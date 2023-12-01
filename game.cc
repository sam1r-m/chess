#include "game.h"
#include <vector>
#include <string>
using namespace std;

Game::Game() {}

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
            } else {
                std::cout << "Invalid player type." << std::endl;
            }

            return;

        } else if (cmd == "setup") {
            setUpMode = true;
            std::cout << board;
            return;

        } else {
            std::cout << "Invalid command." << std::endl;

        }

    }

    // check if Game is in gameMode, only accepts resign
    //  or move commands
    if (gameMode){

        // resign gives point to opposing side
        if (cmd == "resign"){
            endGame();

        } else if (cmd == "move") {
            std::string start, end;
            iss >> start >> end;

            //different for computer, pawn promotion takes 
            //  in additional argument
            vector<int> from_coordinate = convert(start);
            vector<int> to_coordinate = convert(end);
            int fromX = from_coordinate[0];
            int fromY = from_coordinate[1];
            int toX = to_coordinate[0];
            int toY = to_coordinate[1];
            board.makeMove(fromX, fromY, toX, toY);

            if (checkmate) {
                cout << "Checkmate! ";
                blackTurn = !blackTurn;
                endGame();

            } else if (staleMate) {
                whiteScore += 0.5;
                blackScore += 0.5;
                cout << "Stalemate!" << endl;
                gameMode = false;

            } else if (check) {
                blackTurn = !blackTurn;

                if (blackTurn) {
                    cout << "Black";
                } else {
                    cout << "White";
                }
                cout << " is in check."  << endl;

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
            board.removePieceAt(x,y);

        } else if (cmd == "=") {
            std::string color;
            iss >> color;
            changeTurn(color);

        } else if (cmd == "done") {

            //check that there is one king on either side, no pawns are on the
            //  first or last row, and that neitehr king is in check before leaving
            std::cout << board;
            setUpMode = false;

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
    if (wp == "human") whitePlayer = std::make_unique<Human>();
    else if (wp == "computer[1]") whitePlayer = std::make_unique<Computer1>();
    else if (wp == "computer[2]") whitePlayer = std::make_unique<Computer2>();
    else if (wp == "computer[3]") whitePlayer = std::make_unique<Computer3>();
    else if (wp == "computer[4]") whitePlayer = std::make_unique<Computer4>();
    else validPlayer = false;

    //set type of blackPlayer
    if (bp == "human") blackPlayer = std::make_unique<Human>();
    else if (bp == "computer[1]") blackPlayer = std::make_unique<Computer1>();
    else if (bp == "computer[2]") blackPlayer = std::make_unique<Computer2>();
    else if (bp == "computer[3]") blackPlayer = std::make_unique<Computer3>();
    else if (bp == "computer[4]") whitePlayer = std::make_unique<Computer4>();
    else validPlayer = false;

    return validPlayer;
}

void Game::addPiece(string pieceType, string posn) {
    vector<int> coordinate = convert(posn);
    int x = coordinate[0];
    int y = coordinate[1];
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
        cout << "Invalid piece type" << endl;
    }
}

void Game::changeTurn(std::string color){
    if (color == "black") blackTurn = true;
    else if (color == "white") blackTurn = false;
    else std::cout << "Invalid color." << std::endl;
}

void Game::endGame(){
    if (blackTurn){
        whiteScore++;
        cout << "White wins!" << endl;
    } else {
        blackScore++;
        cout << "Black wins!" << endl;
    }

    gameMode = false;
}
