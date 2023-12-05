#ifndef __MOVE_H__
#define __MOVE_H__

class Move {
    int startX, startY, endX, endY; //stores start and end coordinates
    bool captures;  //true if Move captures an enemy Piece

    public:
    Move(int startX, int startY, int endX, int endY, bool captures);

    // Accessors
    int getStartX() const;
    int getStartY() const;
    int getEndX() const;
    int getEndY() const;
    bool doesCapture() const;
    bool getsCaptured() const;
};

#endif
 