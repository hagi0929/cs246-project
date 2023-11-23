#ifndef PLAYER_H
#define PLAYER_H
#include"gameboard.h"
#include"turn.h"

using namespace std;

class Player {
 int score;
 
 public:

 Player();
 virtual ~Player() = 0;
  virtual Turn getNextTurn() = 0;
  int getScore() const;
};

#endif