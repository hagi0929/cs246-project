#include "observer.h"

class Display : public Observer {
 public:
  virtual void show() = 0;
};