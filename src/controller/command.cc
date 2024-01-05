#include "game.h"

using namespace std;

GameCommand::GameCommand(string player1, string player2)
    : player1{player1}, player2{player2} {}
void GameCommand::execute(Game &game, Gameboard &gameboard) {
  game.setPlayer(player1, 0);
  game.setPlayer(player2, 1);
  gameboard.addPiece(Coor{7, 0}, 'R');
  gameboard.addPiece(Coor{7, 1}, 'N');
  gameboard.addPiece(Coor{7, 2}, 'B');
  gameboard.addPiece(Coor{7, 3}, 'Q');
  gameboard.addPiece(Coor{7, 4}, 'K');
  gameboard.addPiece(Coor{7, 5}, 'B');
  gameboard.addPiece(Coor{7, 6}, 'N');
  gameboard.addPiece(Coor{7, 7}, 'R');
  gameboard.addPiece(Coor{6, 0}, 'P');
  gameboard.addPiece(Coor{6, 1}, 'P');
  gameboard.addPiece(Coor{6, 2}, 'P');
  gameboard.addPiece(Coor{6, 3}, 'P');
  gameboard.addPiece(Coor{6, 4}, 'P');
  gameboard.addPiece(Coor{6, 5}, 'P');
  gameboard.addPiece(Coor{6, 6}, 'P');
  gameboard.addPiece(Coor{6, 7}, 'P');
  gameboard.addPiece(Coor{0, 0}, 'r');
  gameboard.addPiece(Coor{0, 1}, 'n');
  gameboard.addPiece(Coor{0, 2}, 'b');
  gameboard.addPiece(Coor{0, 3}, 'q');
  gameboard.addPiece(Coor{0, 4}, 'k');
  gameboard.addPiece(Coor{0, 5}, 'b');
  gameboard.addPiece(Coor{0, 6}, 'n');
  gameboard.addPiece(Coor{0, 7}, 'r');
  gameboard.addPiece(Coor{1, 0}, 'p');
  gameboard.addPiece(Coor{1, 1}, 'p');
  gameboard.addPiece(Coor{1, 2}, 'p');
  gameboard.addPiece(Coor{1, 3}, 'p');
  gameboard.addPiece(Coor{1, 4}, 'p');
  gameboard.addPiece(Coor{1, 5}, 'p');
  gameboard.addPiece(Coor{1, 6}, 'p');
  gameboard.addPiece(Coor{1, 7}, 'p');
  game.setState(GameState::PLAYING);
}

SetUpCommand::SetUpCommand() {}
void SetUpCommand::execute(Game &game, Gameboard &gameboard) {
  game.setState(GameState::SETUP);
}

MoveCommand::MoveCommand(Coor from, Coor to, char piece)
    : from{from}, to{to}, piece{piece} {}
void MoveCommand::execute(Game &game, Gameboard &gameboard) {
  gameboard.movePiece(from, to, piece);
}

ResignCommand::ResignCommand() {}
void ResignCommand::execute(Game &game, Gameboard &gameboard) { game.resign(); }

AddPieceCommand::AddPieceCommand(Coor coor, char piece)
    : coor{coor}, piece{piece} {}
void AddPieceCommand::execute(Game &game, Gameboard &gameboard) {
  gameboard.addPiece(coor, piece);
}

RemovePiece::RemovePiece(Coor coor) : coor{coor} {}
void RemovePiece::execute(Game &game, Gameboard &gameboard) {
  gameboard.removePiece(coor);
}

SetTurn::SetTurn(int playerNum) : playerNum{playerNum} {}
void SetTurn::execute(Game &game, Gameboard &gameboard) {
  gameboard.setTurn(playerNum);
}

DoneSetup::DoneSetup() {}
void DoneSetup::execute(Game &game, Gameboard &gameboard) {
  game.setState(GameState::MENU);
}

QuitCommand::QuitCommand() {}
void QuitCommand::execute(Game &game, Gameboard &gameboard) { exit(0); }
