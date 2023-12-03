#ifndef GAME_H
#define GAME_H
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"
#include "display.h"
#include "gameboard.h"
#include "human.h"

const int NUMOFPLAYERS = 2;
class Game
{
  std::shared_ptr<GameBoard> gameBoard;
  std::shared_ptr<View> display;
  std::shared_ptr<Player> players[NUMOFPLAYERS];
  bool gameInProgress = false;
  bool setupInProgress = false;
  std::istream &in;

public:
  Game(std::istream &in);
  ~Game();
  void play();
  void activate();
  void setupCmd();
  void processCmd();
  std::vector<std::string> parseCmd(std::string cmd);
};

#endif
