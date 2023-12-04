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

