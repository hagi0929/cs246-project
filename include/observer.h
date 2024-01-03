#include "coor.h"

class Observer {
 public:
  virtual void notifyAdd(Coor, char) = 0;
  virtual void notifyRemove(Coor) = 0;
  virtual void notifyMove(Coor, Coor) = 0;
  virtual ~Observer() = default;
};