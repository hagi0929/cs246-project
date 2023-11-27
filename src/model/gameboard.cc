#include "gameboard.h"

using namespace std;

GameBoard::GameBoard() : board{nullptr}, thisTurn{0}, playerColors{{}} {
  cout << "GameBoard ctor is called" << endl;
}
GameBoard::~GameBoard() { cout << "GameBoard dtor is called" << endl; }
void GameBoard::move(Move &m) { thisTurn = (thisTurn + 1) % 2; }
void GameBoard::addPiece(Piece &p, string coor) {
  cout << "GameBoard::addPiece is called" << endl;
}
void GameBoard::removePiece(string coor) {
  cout << "GameBoard::removePiece is called" << endl;
}
void GameBoard::setBeginPlayer(int player) { thisTurn = player; }
void GameBoard::undo(int moves) { cout << "GameBoard::undo is called" << endl; }
void GameBoard::redo(int moves) { cout << "GameBoard::redo is called" << endl; }
int GameBoard::getThisTurn() const { return thisTurn; }
void GameBoard::resign() {
  cout << "player " << thisTurn << " is called" << endl;
}
