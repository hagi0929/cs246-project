#ifndef COMMAND_H
#define COMMAND_H
#include <memory>

#include "coor.h"

class Player;
class Game;

class ICommand {
 public:
  virtual ~ICommand() = default;
  virtual void execute(Game &game) = 0;
};

// menu commands
class GameCommand : public ICommand {
  std::string player1;
  std::string player2;

 public:
  GameCommand(std::string player1, std::string player2);
  void execute(Game &game) override;
};

class SetUpCommand : public ICommand {
 public:
  SetUpCommand();
  void execute(Game &game) override;
};

// ingame commands
class MoveCommand : public ICommand {
  Coor from;
  Coor to;
  char piece;

 public:
  MoveCommand(Coor from, Coor to, char piece);
  void execute(Game &game) override;
};

class ResignCommand : public ICommand {
 public:
  ResignCommand();
  void execute(Game &game) override;
};

// setup commands
class AddPieceCommand : public ICommand {
  Coor coor;
  char piece;

 public:
  AddPieceCommand(Coor coor, char piece);
  void execute(Game &game) override;
};

class RemovePiece : public ICommand {
  Coor coor;

 public:
  RemovePiece(Coor coor);
  void execute(Game &game) override;
};

class DoneSetup : public ICommand {
 public:
  DoneSetup();
  void execute(Game &game) override;
};
class SetTurn : public ICommand {
  int playerNum;
 public:
  SetTurn(int playerNum);
  void execute(Game &game) override;
};

// global commands
class QuitCommand : public ICommand {
 public:
  QuitCommand();
  void execute(Game &game) override;
};
#endif