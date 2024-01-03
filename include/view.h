#ifndef VIEW_H
#define VIEW_H

#include "observer.h"

class Display : public Observer {
 public:
  virtual void show() = 0;
};

#endif