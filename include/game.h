#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <memory>

#include "command.h"
#include "gameboard.h"
#include "gamestate.h"
#include "player.h"
#include "view.h"

enum class GameState {
  SETUP,
  PLAYING,
  MENU,
};

class Game {
  std::istream &in;
  std::unique_ptr<Gameboard> gameboard;
  std::vector<std::shared_ptr<Display>> displays =
      std::vector<std::shared_ptr<Display>>{};
  std::shared_ptr<Player> players[2];
  GameState gameState;
  void executeCommand(std::unique_ptr<ICommand> command);
  std::weak_ptr<Player> getCurrentPlayer();
  std::shared_ptr<ICommand> getCommand();

 public:
  Game(std::istream &in);
  void play();
  void setState(GameState newState);
  void resign();
  void setPlayer(std::string player, int playerNum);
  void showAll();
  std::string getInput();
};

#endif