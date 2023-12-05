#ifndef COMPUTER3_H
#define COMPUTER3_H
#include "computer.h"
class Computer3 : public Computer {
  int calculateScore(std::shared_ptr<Move> move);

 public:
  Computer3(std::shared_ptr<Eyes> eye);

  userCmd getResponse() override;
};

#endif
