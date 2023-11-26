#ifndef GAME_H
#define GAME_H
#include "display.h"
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"
#include "gameboard.h"
#include "human.h"

const int NUMOFPLAYERS = 2;
class Game {
  std::shared_ptr<GameBoard> board;
  std::shared_ptr<Display> display;
  std::shared_ptr<Player> players[NUMOFPLAYERS];
  bool gameStarted = false;

 public:
  Game(GameBoard *board, Display *display);
  ~Game();
  void play();
  void activate();
  bool isValidCmd() const;
  std::vector<std::string> parseCmd(std::string cmd);
};

#endif