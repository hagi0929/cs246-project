#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"

class Computer : public Player {
  GameBoard *board;
 public:
  Computer(GameBoard *board);
};

#endif
