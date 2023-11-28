#include "gameboard.h"

using namespace std;

GameBoard::GameBoard() : thisTurn{0}, playerColors{ {} } {
  cout << "GameBoard ctor is called" << endl;
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      board[i][j] = std::make_shared<Cell>(i, j);
    }
  }
}
GameBoard::~GameBoard() { cout << "GameBoard dtor is called" << endl; }
void GameBoard::move(Move &m) {
  cout << "GameBoard::move is called" << endl;
}
void GameBoard::addPiece(Piece &p, string coor) {
  cout << "GameBoard::addPiece is called" << endl;
}
void GameBoard::removePiece(string coor) {
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
shared_ptr<Cell> GameBoard::getCell(int row, int col) const {
  return board[row][col];
}
