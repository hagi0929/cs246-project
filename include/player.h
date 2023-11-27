#ifndef PLAYER_H
#define PLAYER_H
#include "gameboard.h"
#include "move.h"

enum class cmdType { MOVE, QUIT, RESIGN };

struct userCmd {
  cmdType type;
  std::vector<std::string> cmd = std::vector<std::string>{};
};

class Player {
 protected:
  int score = 0;

 public:
  virtual userCmd getResponse() = 0;
  int getScore() const;
};

#endif