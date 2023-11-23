#include "gameboard.h"
#include "turn.h"

using namespace std;


  // GameBoard();
  // ~GameBoard();
  // bool isValidMove(Turn t) const;
  // bool move(Coor c1, Coor c2);
  // void addPiece(Piece &p, Coor c);
  // void removePiece(Coor c);
  // void setBeginPlayer(Player &p);
  // void undo(int moves);
  // void redo(int moves);
  // int getThisTurn() const;

GameBoard::GameBoard() {
    dout << "GameBoard ctor is called" << endl;
}
GameBoard::~GameBoard() {
    dout << "GameBoard dtor is called" << endl;
}
bool GameBoard::isValidMove(Turn t) const {
  dout << "GameBoard::isValidMove is called" << endl;
    return true;
}
bool GameBoard::move(Coor c1, Coor c2) {
  dout << "GameBoard::move is called" << endl;
    return true;
}
void GameBoard::addPiece(Piece &p, Coor c) {
  dout << "GameBoard::addPiece is called" << endl;
}
void GameBoard::removePiece(Coor c) {
  dout << "GameBoard::removePiece is called" << endl;
}
void GameBoard::setBeginPlayer(Player &p) {
  dout << "GameBoard::setBeginPlayer is called" << endl;
}
void GameBoard::undo(int moves) {
  dout << "GameBoard::undo is called" << endl;
}
void GameBoard::redo(int moves) {
  dout << "GameBoard::redo is called" << endl;
}
int GameBoard::getThisTurn() const {
  dout << "GameBoard::getThisTurn is called" << endl;
    return 0;
}