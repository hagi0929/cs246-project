#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <memory>

#include "command.h"
#include "gameboard.h"
#include "gamestate.h"
#include "player.h"

class Game {
  std::istream &in;
  std::unique_ptr<Gamestate> gamestate;
  std::unique_ptr<Gameboard> gameboard;
  std::shared_ptr<Player> players[2];

 public:
  Game(std::istream &in);
  void play();
  void setState(Gamestate *newState);
  std::weak_ptr<Player> getCurrentPlayer();
  void addPieceToBoard(const Coor &coor, char piece);
  void removePieceFromBoard(const Coor &coor);
  void movePiece(const Coor &from, const Coor &to, char promotion);
  void setThisTurn(int turn);
  void setPlayer(std::string player, int playerNum);
  void resign();
  void executeCommand(std::unique_ptr<ICommand> command);
  std::string getInput();
};

#endif