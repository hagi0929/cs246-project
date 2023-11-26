#ifndef COMPUTER1_H
#define COMPUTER1_H
#include "move.h"
#include "player.h"

using namespace std;
class Computer1 : public Player {
  GameBoard *board;

 public:
  Computer1(GameBoard *board);
  Move &getNextTurn();
  int getScore() const;
};
#endif