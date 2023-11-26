#ifndef GAME_H
#define GAME_H
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"
#include "gameboard.h"
#include "human.h"

using namespace std;

const int NUMOFPLAYERS = 2;
class Game {
  shared_ptr<GameBoard> board;
  shared_ptr<Player> players[NUMOFPLAYERS];
  bool gameStarted = false;

 public:
  Game();
  ~Game();
  void play();
  void activate();
  vector<string> parseCmd(string cmd);
};

#endif