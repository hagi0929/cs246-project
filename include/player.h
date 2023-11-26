#ifndef PLAYER_H
#define PLAYER_H
#include "gameboard.h"
#include "move.h"

class Player {
 protected:
  int score = 0;

 public:
  virtual Move &getNextTurn() = 0;
  int getScore() const;
};

#endif