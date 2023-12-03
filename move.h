#ifndef __MOVE_H__
#define __MOVE_H__

class Move {
    int startX, startY, endX, endY;
    bool captures;

    public:
    // Constructor
    Move(int startX, int startY, int endX, int endY, bool captures);

    // Accessors
    int getStartX() const;
    int getStartY() const;
    int getEndX() const;
    int getEndY() const;
    bool doesCapture() const;
};

#endif
 