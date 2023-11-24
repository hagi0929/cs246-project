#ifndef PLAYER_H
#define PLAYER_H
#include "gameboard.h"
#include "turn.h"

using namespace std;

class Player {
 protected:
  int score;
 
 public:

  Player();
  virtual ~Player();
  virtual Turn &getNextTurn() = 0;
  int getScore() const;
};

#endif