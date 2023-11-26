#ifndef PLAYER_H
#define PLAYER_H
#include "gameboard.h"
#include "move.h"
using namespace std;

class Player {
 protected:
  int score = 0;

 public:
  virtual Move &getNextTurn() = 0;
  virtual int getScore() const = 0;
};

#endif