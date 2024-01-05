#include "game.h"
#include "player.h"

class Computer : public Player {
 protected:
  Game& game;

 public:
  Computer(Game& game);
};

class Computer1 : public Computer {
 public:
  Computer1(Game& game);
  std::shared_ptr<ICommand> getCommand() override;
};

class Computer2 : public Computer {
 public:
  Computer2(Game& game);
  std::shared_ptr<ICommand> getCommand() override;
};

class Computer3 : public Computer {
 public:
  Computer3(Game& game);
  std::shared_ptr<ICommand> getCommand() override;
};

class Computer4 : public Computer {
 public:
  Computer4(Game& game);
  std::shared_ptr<ICommand> getCommand() override;
};
