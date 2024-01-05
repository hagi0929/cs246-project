#include "game.h"
#include "player.h"
#include "snapshot.h"
class Computer1 : public Player {
 public:
  Computer1(Game& game, int playerNum);
  std::shared_ptr<ICommand> getCommand() override;
};

class Computer2 : public Player {
 public:
  Computer2(Game& game, int playerNum);
  std::shared_ptr<ICommand> getCommand() override;
};

class Computer3 : public Player {
 public:
  Computer3(Game& game, int playerNum);
  std::shared_ptr<ICommand> getCommand() override;
};

class Computer4 : public Player {
  int predictScore(std::shared_ptr<Snapshot> snapshot, int depth, int team);
 public:
  Computer4(Game& game, int playerNum);
  std::shared_ptr<ICommand> getCommand() override;
};
