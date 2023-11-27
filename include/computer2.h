#ifndef COMPUTER2_H
#define COMPUTER2_H
#include "computer.h"

class Computer2 : public Computer {
 public:
  userCmd getResponse() override;
};

#endif
