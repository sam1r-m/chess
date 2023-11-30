// View
#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include "observer.h"

class TextDisplay: public Observer {
    std::vector<std::vector<char>> theDisplay;
    const int boardSize = 8;
    
    public:
    TextDisplay();
    ~TextDisplay();

    void notify(Square &s) override;

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
