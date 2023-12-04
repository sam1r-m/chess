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
    std::vector<std::vector<char>> theDisplay;  // To store the current state of the board

public:
    GraphicsDisplay(int boardSize, int width, int height);
    void notify(Square &s) override;
    void redraw();  // Redraws the entire board
};


#endif