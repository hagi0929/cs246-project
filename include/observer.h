#ifndef OBSERVER_H
#define OBSERVER_H

#include "cell.h"

class Observer {
  public:
    virtual void notify(Cell &c) = 0;
    virtual ~Observer() = default;
};

#endif
