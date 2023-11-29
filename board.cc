#include "board.h"

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

    // set up pieces in starting postitions

}

void Board::addPieceAt(int x, int y, Color color, std::unique_ptr<Piece> piece){
    pieces.emplace_back(piece);
    changeCoords(&x, &y);
    
    
}

void Board::removePieceAt(int x, int y){
    changeCoords(&x, &y);


}

bool Board::makeMove(int fromX, int fromY, int toX, int toY){
    changeCoords(&fromX, &fromY);
    changeCoords(&toX, &toY);


}
