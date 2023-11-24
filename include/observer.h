#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "cell.h"

class Cell;

class Observer {
  public:
    virtual void notify(Cell &c) = 0;
    virtual ~Observer() = default;
};

#endif