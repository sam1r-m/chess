#include <iostream>
#include "textDisplay.h"



TextDisplay::TextDisplay(){

}

TextDisplay::~TextDisplay(){}

void TextDisplay::notify(Square &s){

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
    out << "\nabcdefgh\n";
    return out;
}