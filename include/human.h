#include <iostream>

#include "player.h"

class Human : public Player {
  Game &game;

 public:
  Human(Game &game);
  std::shared_ptr<ICommand> getCommand() override;
};