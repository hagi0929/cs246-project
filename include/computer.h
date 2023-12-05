#ifndef COMPUTER_H
#define COMPUTER_H
#include "eyes.h"
#include "player.h"
#include <algorithm>

class Computer : public Player {
 protected:
  std::shared_ptr<Eyes> eye;

 public:
  Computer(std::shared_ptr<Eyes> eye);
};

#endif
