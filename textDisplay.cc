#include <iostream>
#include "textDisplay.h"
#include "square.h"

void TextDisplay::addPiece(int x, int y, char piece){
    theDisplay[y][x] = piece;
}

TextDisplay::TextDisplay(){
    std::vector<char> row = {' ', '_', ' ', '_', ' ', '_', ' ', '_'};
    std::vector<char> row1 = {'_', ' ', '_', ' ', '_', ' ', '_', ' '};

    //set up the grid
    for (int i = 0; i < boardSize / 2; ++i) {
        theDisplay.emplace_back(row);
        theDisplay.emplace_back(row1);
    }

    //initialize black pieces
    addPiece(0, 0, 'r');
    addPiece(1, 0, 'n');
    addPiece(2, 0, 'b');
    addPiece(3, 0, 'q');
    addPiece(4, 0, 'k');
    addPiece(5, 0, 'b');
    addPiece(6, 0, 'n');
    addPiece(7, 0, 'r');

    for (int i = 0; i < boardSize; ++i) {
        addPiece(i, 1, 'p');
    }

    //initialize white pieces
    for (int j = 0; j < boardSize; ++j) {
        addPiece(j, 6, 'P');
    }

    addPiece(0, 7, 'R');
    addPiece(1, 7, 'N');
    addPiece(2, 7, 'B');
    addPiece(3, 7, 'Q');
    addPiece(4, 7, 'K');
    addPiece(5, 7, 'B');
    addPiece(6, 7, 'N');
    addPiece(7, 7, 'R');
}

TextDisplay::~TextDisplay(){}

void TextDisplay::notify(Square &s){
    int x = s.getX() - 1;
    int y = boardSize - s.getY();

    //if there's Piece on Square s, update to Piece char
    if (s.isOccupied()){
        theDisplay[y][x] = s.getPiece()->getChar();

    //if no Piece, update to corresponding Square char
    } else {
        if ((x + y) % 2){
            theDisplay[y][x] = '_';
        } else {
            theDisplay[y][x] = ' ';
        }
    }
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
    for (int i = 0; i < td.boardSize; ++i){
        int index = 8 - i;
        out << index << " ";

        for (int j = 0; j < td.boardSize; ++j){
            out << td.theDisplay[i][j];
        }
        out << '\n';
    }
    out << "\n  abcdefgh\n";
    return out;
}
