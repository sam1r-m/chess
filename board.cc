#include "board.h"

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
