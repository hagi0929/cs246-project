#ifndef COMPUTER3_H
#define COMPUTER3_H
#include "computer.h"

class Computer3 : public Computer {
 public:
  userCmd getResponse() override;
};

#endif
