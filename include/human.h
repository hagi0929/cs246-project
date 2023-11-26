#ifndef HUMAN_H
#define HUMAN_H
#include "move.h"
#include "player.h"

using namespace std;
class Human : public Player {
 public:
  Human();
  ~Human();
  Move &getNextTurn() override;
  int getScore() const override;
};

#endif