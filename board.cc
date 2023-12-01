#include "board.h"
using namespace std;
// changeCoords(x, y) converts given x and y 
//  coordinates into their corresponding array indices
void changeCoords(int *x, int *y){
    *x -= 1;
    *y = 8 - *y;
}

Board::Board(){
    td = std::make_unique<TextDisplay>();

    // create rows of squares with corresponding coordinates
    for (int i = boardSize; i > 0; --i){
        std::vector<Square> row;

        for (int j = 1; j <= boardSize; ++j){
            row.emplace_back(Square(j, i));
        }

        board.emplace_back(row);
    }

    for (int k = 0; k < boardSize; ++k){
        for (int l = 0; l < boardSize; ++l){
            board[k][l].attach(td.get());
            //attach graphicsDisplay
        }
    }

    // set up pieces in starting postitions

}

Board::~Board() {}

void Board::addPieceAt(int x, int y, std::unique_ptr<Piece> piece){
    pieces.emplace_back(std::move(piece));
    changeCoords(&x, &y);
    
    
}

void Board::removePieceAt(int x, int y){
    bool found = false;

    for (int i = 0; i < pieces.size(); ++i){
	    if (x == pieces[i].get()->getX() && y == pieces[i].get()->getY()){
            pieces[i] == nullptr;
            found = true;
        }
    } 

    if (!found) return;

    changeCoords(&x, &y);
    
}

bool Board::makeMove(int fromX, int fromY, int toX, int toY){
    changeCoords(&fromX, &fromY);
    changeCoords(&toX, &toY);

}

// added getSquareAt
const Square& Board::getSquareAt(int x, int y) const {
    return board[x][y];
}

// added getBoard()

const vector<vector<Square>>& Board::getBoard() const {
    return board;
}

std::ostream &operator<<(std::ostream &out, const Board &b){
    out << *(b.td);
    return out;
}
