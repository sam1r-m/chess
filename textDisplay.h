// View
#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include "observer.h"

class TextDisplay: public Observer {
    public:
    TextDisplay();
    ~TextDisplay();

    void notify(Square &s) override;

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
