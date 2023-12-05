#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <vector>
#include "piece.h"
#include "observer.h"

class Square {
    const int xPos; //x coordinate of Square (1-8)
    const int yPos; //y coordinate of Square (1-8)
    Piece *piece = nullptr; //pointer to Piece occupying Square (nullptr if empty)
    std::vector<Observer*> observers;

    public:
    Square(int xPos, int yPos);
    ~Square();

    //Accessors
    int getX();
    int getY();
    Piece *getPiece() const;    //returns pointer to Piece on Square
    bool isOccupied() const;    //true if there is Piece occuying Square

    void addPiece(Piece *p);    //adds Piece to Square
    void attach(Observer *o);   
    void detachObservers(); 
    void notifyObservers(); 
};

#endif
