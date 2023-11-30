#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include "square.h"

class Observer {
public:
    virtual void notify(Square &s) = 0;
    virtual ~Observer() = default; // default virtual destructor
};

#endif
