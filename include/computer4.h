#ifndef COMPUTER4_H
#define COMPUTER4_H
#include "computer.h"

class Computer4 : public Computer {
  int calculateScore(std::shared_ptr<Move> move, int depth);

 public:
  Computer4(std::shared_ptr<Eyes> eye);

  userCmd getResponse() override;
};

#endif
