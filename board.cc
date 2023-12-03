#include "board.h"
using namespace std;
// changeCoords(x, y) converts given x and y 
//  coordinates into their corresponding array indices
void changeCoords(int *x, int *y){
    *x -= 1;
    *y = 8 - *y;
}

Board::Board(){
    // create rows of squares with corresponding coordinates
    for (int i = boardSize; i > 0; --i){
        std::vector<Square> row;

        for (int j = 1; j <= boardSize; ++j){
            row.emplace_back(Square(j, i));
        }

        board.emplace_back(row);
    }
}

Board::~Board() {}

void Board::initializeBoard(){
    td = std::make_unique<TextDisplay>();

    //add Black Pieces
    std::unique_ptr<Rook> BRook1 = std::make_unique<Rook>(Color::BLACK, 1, 8);
    addPieceAt(1, 8, std::move(BRook1));

    std::unique_ptr<Knight> BKnight1 = std::make_unique<Knight>(Color::BLACK, 2, 8);
    addPieceAt(2, 8, std::move(BKnight1));

    std::unique_ptr<Bishop> BBishop1 = std::make_unique<Bishop>(Color::BLACK, 3, 8);
    addPieceAt(3, 8, std::move(BBishop1));

    std::unique_ptr<Queen> BQueen = std::make_unique<Queen>(Color::BLACK, 4, 8);
    addPieceAt(4, 8, std::move(BQueen));

    std::unique_ptr<King> BKing = std::make_unique<King>(Color::BLACK, 5, 8);
    addPieceAt(5, 8, std::move(BKing));

    std::unique_ptr<Bishop> BBishop2 = std::make_unique<Bishop>(Color::BLACK, 6, 8);
    addPieceAt(6, 8, std::move(BBishop2));

    std::unique_ptr<Knight> BKnight2 = std::make_unique<Knight>(Color::BLACK, 7, 8);
    addPieceAt(7, 8, std::move(BKnight2));

    std::unique_ptr<Rook> BRook2 = std::make_unique<Rook>(Color::BLACK, 8, 8);
    addPieceAt(8, 8, std::move(BRook2));

    for (int k = 1; k <= boardSize; ++k){
        std::unique_ptr<Pawn> BPawn = std::make_unique<Pawn>(Color::BLACK, k, 7);
        addPieceAt(k, 7, std::move(BPawn));
    }

    //add White Pieces
    for (int l = 1; l <= boardSize; ++l){
        std::unique_ptr<Pawn> WPawn = std::make_unique<Pawn>(Color::WHITE, l, 2);
        addPieceAt(l, 2, std::move(WPawn));
    }

    std::unique_ptr<Rook> WRook1 = std::make_unique<Rook>(Color::WHITE, 1, 1);
    addPieceAt(1, 1, std::move(WRook1));

    std::unique_ptr<Knight> WKnight1 = std::make_unique<Knight>(Color::WHITE, 2, 1);
    addPieceAt(2, 1, std::move(WKnight1));

    std::unique_ptr<Bishop> WBishop1 = std::make_unique<Bishop>(Color::WHITE, 3, 1);
    addPieceAt(3, 1, std::move(WBishop1));

    std::unique_ptr<Queen> WQueen = std::make_unique<Queen>(Color::WHITE, 4, 1);
    addPieceAt(4, 1, std::move(WQueen));

    std::unique_ptr<King> WKing = std::make_unique<King>(Color::WHITE, 5, 1);
    addPieceAt(5, 1, std::move(WKing));

    std::unique_ptr<Bishop> WBishop2 = std::make_unique<Bishop>(Color::WHITE, 6, 1);
    addPieceAt(6, 1, std::move(WBishop2));

    std::unique_ptr<Knight> WKnight2 = std::make_unique<Knight>(Color::WHITE, 7, 1);
    addPieceAt(7, 1, std::move(WKnight2));

    std::unique_ptr<Rook> WRook2 = std::make_unique<Rook>(Color::WHITE, 8, 1);
    addPieceAt(8, 1, std::move(WRook2));

    for (int k = 0; k < boardSize; ++k){
        for (int l = 0; l < boardSize; ++l){
            board[k][l].attach(td.get());
            //attach graphicsDisplay
        }
    }
}

void Board::resetBoard(){
    for (int i = 1; i <= boardSize; ++i){
        for (int j = 1; j <= boardSize; ++j){
            removePieceAt(i, j);
        }
    }

    //remove Observers
    for (int k = 0; k < boardSize; ++k){
        for (int l = 0; l < boardSize; ++l){
            board[k][l].detachObservers();
            //detach graphicsDisplay
        }
    }
}

void Board::addPieceAt(int x, int y, std::unique_ptr<Piece> piece){
    changeCoords(&x, &y);
    
    //if there is a Piece currently on the Square, remove it
    if (board[y][x].isOccupied()){
        removePieceAt(x + 1, 8 - y);
    }

    pieces.push_back(std::move(piece));
    board[y][x].addPiece(pieces.back().get());
    board[y][x].notifyObservers();
}

void Board::removePieceAt(int x, int y){
    for (auto it = pieces.begin(); it != pieces.end(); ++it) {
        if (x == it->get()->getX() && y == it->get()->getY()) {
            pieces.erase(it);

            changeCoords(&x, &y);
            
            board[y][x].addPiece(nullptr);
            board[y][x].notifyObservers();

            return;
        }
    }
}

void Board::makeMove(int fromX, int fromY, int toX, int toY){
    Piece *p = getSquareAt(fromX - 1, 8 - fromY).getPiece();

    removePieceAt(toX, toY);

    for (int i = 0; i < pieces.size(); ++i){
        if (p == pieces[i].get()) {
            pieces[i]->setX(toX);
            pieces[i]->setY(toY);
            break;
        }
    }

    changeCoords(&toX, &toY);
    board[toY][toX].addPiece(p);
    board[toY][toX].notifyObservers();

    changeCoords(&fromX, &fromY);
    board[fromY][fromX].addPiece(nullptr);
    board[fromY][fromX].notifyObservers();
}

// added getSquareAt
const Square& Board::getSquareAt(int x, int y) const {
    return board[y][x];
}

// added getBoard()

const vector<vector<Square>>& Board::getBoard() const {
    return board;
}

std::ostream &operator<<(std::ostream &out, const Board &b){
    out << *(b.td);
    return out;
}
