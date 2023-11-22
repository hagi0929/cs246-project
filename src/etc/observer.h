#ifndef _OBSERVER_H_
#define _OBSERVER_H_
class Game;

class Observer {
  public:
    virtual void notify(Game &game) = 0;
    virtual ~Observer() = default;
}