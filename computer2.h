#ifndef COMPUTER2_H
#define COMPUTER2_H
#include "computer.h"

class Computer2 : public Computer {
 public:
  Computer2(std::shared_ptr<Eyes> eye);

  userCmd getResponse() override;
};

#endif
