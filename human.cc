#include "human.h"

Human::Human(Color c, Board *board): Player(c, board) {
    humanPlayer = true;
}

Human::~Human() {}

void Human::makeMove(){

}
