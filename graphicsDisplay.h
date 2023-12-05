#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__

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

#endif
