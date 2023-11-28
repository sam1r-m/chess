#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

#include <vector>

class Subject {
  std::vector<Observer*> observers;

 public:
  virtual ~Subject() = default;

  void attach(Observer *o);
  void detach(Observer *o);

  void notifyAllObservers();
};

#endif