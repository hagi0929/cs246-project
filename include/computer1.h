#ifndef COMPUTER1_H
#define COMPUTER1_H
#include "computer.h"

class Computer1 : public Computer {
 public:
  Computer1(std::shared_ptr<Eyes> eye);
  userCmd getResponse() override;
};

#endif
