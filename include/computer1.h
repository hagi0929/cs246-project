#ifndef COMPUTER1_H
#define COMPUTER1_H
#include "computer.h"

class Computer1 : public Computer {
 public:
  Move &getNextTurn() override;
};

#endif
