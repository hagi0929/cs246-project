#include "king.h"
using namespace std;

vector<shared_ptr<Move>> King::possibleMoves() const {
  cout << "King possibleMoves() is called" << endl;
  vector<shared_ptr<Move>> validMoves;
  for (int r = row - 1; r <= row + 1; ++r) {
    if (r < 0 || r > 7) continue;
    for (int c = col - 1; c <= col + 1; ++c) {
      if (c < 0 || c > 7 || (r == row && c == col) || ((eyes->isOccupied(r, c)) && !eyes->isOpponent(r, c))) {
        continue;
      }
      shared_ptr<Move> mp{ new Move{row, col, r, c, ""} };
      validMoves.emplace_back(mp);
      cout << mp->getCurRow() << "," << mp->getCurCol() + " " << mp->getDestRow() << "," << mp->getDestCol() << endl;
    }
  }

  return validMoves;
}

char King::getType() const { 
  cout << "King getType() is called" << endl;
  return color == Color::White ? 'K' : 'k';
}
