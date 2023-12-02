#include "human.h"

Human::Human(Color c, Board *board): Player(c, board) {
    isHuman = true;
}

Human::~Human() {}

void Human::makeMove(){

}
