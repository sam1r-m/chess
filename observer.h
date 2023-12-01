#ifndef __OBSERVER_H__
#define __OBSERVER_H__
class Square;

class Observer {
public:
    virtual void notify(Square &s) = 0;
    virtual ~Observer() = default; // default virtual destructor
};

#endif
