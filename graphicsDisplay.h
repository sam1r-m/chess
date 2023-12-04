// // View
// #ifndef __GRAPHICSDISPLAY_H__
// #define __GRAPHICSDISPLAY_H__

// #include <iostream>
// #include <vector>

// #include "observer.h"
// #include "window.h"

// class GraphicsDisplay : public Observer {
//     Xwindow xw;
//     int boardSize;
//     const std::vector<std::vector<Square>> &boardRepresentation;

// public:
//    GraphicsDisplay(int width, int height, int boardSize, const std::vector<std::vector<Square>> &boardData);
//     void notify(Square &s) override;
//     void drawBoard();
//     void drawPiece(Square &square);
// };


// #endif

#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "window.h"
#include <vector>
#include "square.h"

class GraphicsDisplay {
private:
    Xwindow xw;
    const std::vector<std::vector<Square>> &boardRepresentation;

public:
    GraphicsDisplay(const std::vector<std::vector<Square>> &boardData);
    void drawBoard();
};

#endif // GRAPHICSDISPLAY_H