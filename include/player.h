#ifndef PLAYER_H
#define PLAYER_H

#include "command.h"
class Player {
  int score = 0;

 public:
  virtual std::shared_ptr<ICommand> getCommand() = 0;
  void addScore(int);
  int getScore() const;
  void setScore(int);
};

#endif