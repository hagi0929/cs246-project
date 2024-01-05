#ifndef PLAYER_H
#define PLAYER_H

#include "command.h"
class Player {
 protected:
  int score = 0;
  Game& game;
  int playerNum = 0;

 public:
  Player(Game& game, int playerNum) : game{game}, playerNum{playerNum} {}
  virtual std::shared_ptr<ICommand> getCommand() = 0;
  void addScore(int);
  int getScore() const;
  void setScore(int);
};

#endif