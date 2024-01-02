#include "gameboard.h"

#include <iostream>

#include "coor.h"

using namespace std;

Gameboard::Gameboard() { init(); }
Cell &Gameboard::getCell(int row, int col) { return board[row][col]; }
void Gameboard::init() {}
int Gameboard::getThisTurn() { return thisTurn; }
void Gameboard::createPiece(const Coor &coor, char pieceType) {}
void Gameboard::removePiece(const Coor &coor) {}
void Gameboard::movePiece(const Coor &from, const Coor &to, char promotion) {
  cout << "player " << thisTurn << " moved piece from " << from << " to " << to
       << endl;
  thisTurn = thisTurn == 0 ? 1 : 0;
}
void Gameboard::setThisTurn(int turn) { thisTurn = turn; }
void Gameboard::resign() {}
vector<shared_ptr<Piece>> Gameboard::getPieces() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j].getPiece() != nullptr) {
        pieces.emplace_back(board[i][j].getPiece());
      }
    }
  }
  return pieces;
}

vector <shared_ptr<Piece>> Gameboard::getCapturedPieces() {
  return capturedPieces;
}