#ifndef OBSERVER_H
#define OBSERVER_H

class Cell;

class Observer
{
public:
  virtual void notify(Cell &c) = 0;
  virtual ~Observer() = default;
};

#endif
