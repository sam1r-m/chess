#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <vector>
#include <iostream>
#include "piece.h"
#include "observer.h"

class Square {
    const int xPos;
    const int yPos;
    Piece *piece;
    std::vector<Observer*> observers;

    public:
    Square(int xPos, int yPos); // (xPos, yPos) -> Square Coordinates
    ~Square();

    int getX();
    int getY();
    Piece *getPiece() const;
    bool isOccupied() const;

    void addPiece(Piece *p);
    void attach(Observer *o);
    void detachObservers();
    void notifyObservers();
    friend std::ostream &operator<<(std::ostream &out, Square &square); //might not be necessary
};

#endif
