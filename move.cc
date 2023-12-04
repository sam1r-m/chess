#include "move.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Move::Move(int startX, int startY, int endX, int endY, bool captures) 
    : startX(startX), startY(startY), endX(endX), endY(endY), captures(captures) {}

int Move::getStartX() const {
    return startX;
}

int Move::getStartY() const {
    return startY;
}

int Move::getEndX() const {
    return endX;
}

int Move::getEndY() const {
    return endY;
}

bool Move::doesCapture() const {
    return captures;
}

bool Move::getsCaptured() const {
    // add logic for whether the move can get captured
    return false; // placeholder
}