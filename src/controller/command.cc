#include "game.h"

using namespace std;

GameCommand::GameCommand(string player1, string player2)
    : player1{player1}, player2{player2} {}
void GameCommand::execute(Game &game) {
  game.setPlayer(player1, 0);
  game.setPlayer(player2, 1);
  game.addPieceToBoard(Coor{"a8"}, 'K');
  game.addPieceToBoard(Coor{"b2"}, 'k');
  game.setState(new InGameState());
}

SetUpCommand::SetUpCommand() {}
void SetUpCommand::execute(Game &game) { game.setState(new SetupState()); }

MoveCommand::MoveCommand(Coor from, Coor to, char piece)
    : from{from}, to{to}, piece{piece} {}
void MoveCommand::execute(Game &game) { game.movePiece(from, to, piece); }

ResignCommand::ResignCommand() {}
void ResignCommand::execute(Game &game) { game.resign(); }

AddPieceCommand::AddPieceCommand(Coor coor, char piece)
    : coor{coor}, piece{piece} {}
void AddPieceCommand::execute(Game &game) { game.addPieceToBoard(coor, piece); }

RemovePiece::RemovePiece(Coor coor) : coor{coor} {}
void RemovePiece::execute(Game &game) { game.removePieceFromBoard(coor); }

SetTurn::SetTurn(int playerNum) : playerNum{playerNum} {}
void SetTurn::execute(Game &game) { game.setThisTurn(playerNum); }

DoneSetup::DoneSetup() {}
void DoneSetup::execute(Game &game) { game.setState(new MenuState()); }

QuitCommand::QuitCommand() {}
void QuitCommand::execute(Game &game) { exit(0); }
