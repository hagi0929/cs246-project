#include <iostream>

#include "player.h"

class Human : public Player {

 public:
  Human(Game &game, int playerNum);
  std::shared_ptr<ICommand> getCommand() override;
};