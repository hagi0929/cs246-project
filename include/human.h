#ifndef HUMAN_H
#define HUMAN_H
#include "move.h"
#include "player.h"

class Human : public Player {
 public:
  Human();
  ~Human();
  Move &getNextTurn() override;
};

#endif