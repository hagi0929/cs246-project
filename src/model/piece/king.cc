#include "king.h"
using namespace std;

King::King(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> King::possibleMoves() const {
  vector<shared_ptr<Move>> validMoves;
  for (int r = coor.first - 1; r <= coor.first + 1; ++r) {
    if (r < 0 || r > 7) continue;
    for (int c = coor.second - 1; c <= coor.second + 1; ++c) {
      if (c < 0 || c > 7 || (r == coor.first && c == coor.second) ||
          (eyes->isOccupied({r, c}) && !eyes->isOpponent({r, c}))) {
        continue;
      }
      shared_ptr<Move> mp{new Move{coor, {r, c}, ' '}};
      validMoves.emplace_back(mp);
    }
  }

  return validMoves;
}

char King::getType() const {
  return getPlayer() == 0 ? 'K' : 'k';
}
