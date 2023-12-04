// View
#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__

#include <iostream>
#include <vector>

#include "observer.h"
#include "window.h"

class GraphicsDisplay : public Observer {
    Xwindow xw;
    int boardSize;

public:
   GraphicsDisplay(int width, int height, int boardSize);
    void notify(Square &s) override;
    void drawBoard();
    void drawPiece(Square &square);
};


#endif