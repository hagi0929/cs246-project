#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <memory>
#include <string>

#include "player.h"

class Game;
class ICommand;

class Gamestate {
 protected:
 public:
  virtual ~Gamestate() = default;
  virtual std::shared_ptr<ICommand> getCommand(Game& game) = 0;
  virtual std::string headmessage() = 0;
};

class SetupState : public Gamestate {
 public:
  std::string headmessage() override;
  std::shared_ptr<ICommand> getCommand(Game& game) override;
};

class InGameState : public Gamestate {
 public:
  std::string headmessage() override;
  std::shared_ptr<ICommand> getCommand(Game& game) override;
};

class MenuState : public Gamestate {
 public:
  std::string headmessage() override;
  std::shared_ptr<ICommand> getCommand(Game& game) override;
};

#endif