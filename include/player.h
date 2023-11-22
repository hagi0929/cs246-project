#ifndef PLAYER_H
#define PLAYER_H
#include"gameBoard.h"
#include"turn.h"

using namespace std;

class Player {
 int score;
 public:
  virtual Turn getNextTurn() = 0;
  virtual int getScore() const = 0;
};

#endif