#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human : public Player {
  std::istream &in;

 public:
  Human(std::istream &in);
  ~Human();
  userCmd getResponse() override;
};

#endif
