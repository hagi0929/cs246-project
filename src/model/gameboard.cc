#include "gameboard.h"

#include "move.h"

using namespace std;

GameBoard::GameBoard() { cout << "GameBoard ctor is called" << endl; }
GameBoard::~GameBoard() { cout << "GameBoard dtor is called" << endl; }
bool GameBoard::isValidMove(Move &t) const {
  cout << "GameBoard::isValidMove is called" << endl;
  return true;
}
bool GameBoard::move(Coor c1, Coor c2) {
  cout << "GameBoard::move is called" << endl;
  return true;
}
void GameBoard::addPiece(Piece &p, Coor c) {
  cout << "GameBoard::addPiece is called" << endl;
}
void GameBoard::removePiece(Coor c) {
  cout << "GameBoard::removePiece is called" << endl;
}
void GameBoard::setBeginPlayer(int player) {
  cout << "GameBoard::setBeginPlayer is called" << endl;
}
void GameBoard::undo(int moves) { cout << "GameBoard::undo is called" << endl; }
void GameBoard::redo(int moves) { cout << "GameBoard::redo is called" << endl; }
int GameBoard::getThisTurn() const {
  cout << "GameBoard::getThisTurn is called" << endl;
  return 0;
}
