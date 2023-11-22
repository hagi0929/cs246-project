#include "GameBoard.h"

GameBoard::GameBoard() {
  dout << "GameBoard ctor called" << endl;
}

GameBoard::~GameBoard() {
  dout << "GameBoard des called" << endl;
}

bool GameBoard::isValidMove(Turn t) const {
  dout << "isValidMove called" << endl;
  return false;
}

bool GameBoard::move(Coor c, Coor c) {
  dout << "move called" << endl;
  return false;
}

void GameBoard::addPiece(Piece &p, Coor c) {
  dout << "addPiece called" << endl;
}

void GameBoard::removePiece(Coor c) {
  dout << "removePiece called" << endl;
}

void GameBoard::setBeginPlayer(Player &p) {
  dout << "setBeginPlayer called" << endl;
}

void GameBoard::undo(int moves) {
  dout << "undo called" << endl;
}

void GameBoard::redo(int moves) {
  dout << "redo called" << endl;
}

int GameBoard::getThisTurn() const {
  dout << "getThisTurn called" << endl;
  return thisTurn;
}
