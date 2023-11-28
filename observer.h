#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Subject;

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default; // default virtual destructor
};

#endif
