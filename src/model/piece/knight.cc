#include "knight.h"
using namespace std;

Knight::Knight(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Knight::possibleMoves(bool checkSafety) const {
  vector<shared_ptr<Move>> validMoves;

  if (coor.first - 2 >= 0) {
    if (coor.second - 1 >= 0 &&
        (!eyes->isOccupied({coor.first - 2, coor.second - 1}) ||
         eyes->isOpponent({coor.first - 2, coor.second - 1}))) {
      shared_ptr<Move> m{
          new Move{coor, {coor.first - 2, coor.second - 1}, ' '}};
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
        validMoves.emplace_back(m);
      }
    }
    if (coor.second + 1 <= 7 &&
        (!eyes->isOccupied({coor.first - 2, coor.second + 1}) ||
         eyes->isOpponent({coor.first - 2, coor.second + 1}))) {
      shared_ptr<Move> m{
          new Move{coor, {coor.first - 2, coor.second + 1}, ' '}};
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
        validMoves.emplace_back(m);
      }
    }
  }
  if (coor.first - 1 >= 0) {
    if (0 && coor.second - 2 >= 0 &&
        (!eyes->isOccupied({coor.first - 1, coor.second - 2}) ||
         eyes->isOpponent({coor.first - 1, coor.second - 2}))) {
      shared_ptr<Move> m{
          new Move{coor, {coor.first - 1, coor.second - 2}, ' '}};
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
        validMoves.emplace_back(m);
      }
    }
    if (coor.second + 2 <= 7 &&
        (!eyes->isOccupied({coor.first - 1, coor.second + 2}) ||
         eyes->isOpponent({coor.first - 1, coor.second + 2}))) {
      shared_ptr<Move> m{
          new Move{coor, {coor.first - 1, coor.second + 2}, ' '}};
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
        validMoves.emplace_back(m);
      }
    }
  }
  if (coor.first + 1 <= 7) {
    if (coor.second - 2 >= 0 &&
        (!eyes->isOccupied({coor.first + 1, coor.second - 2}) ||
         eyes->isOpponent({coor.first + 1, coor.second - 2}))) {
      shared_ptr<Move> m{
          new Move{coor, {coor.first + 1, coor.second - 2}, ' '}};
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
        validMoves.emplace_back(m);
      }
    }
    if (coor.second + 2 <= 7 &&
        (!eyes->isOccupied({coor.first + 1, coor.second + 2}) ||
         eyes->isOpponent({coor.first + 1, coor.second + 2}))) {
      shared_ptr<Move> m{
          new Move{coor, {coor.first + 1, coor.second + 2}, ' '}};
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
        validMoves.emplace_back(m);
      }
    }
  }
  if (coor.first + 2 <= 7) {
    if (coor.second - 1 >= 0 &&
        (!eyes->isOccupied({coor.first + 2, coor.second - 1}) ||
         eyes->isOpponent({coor.first + 2, coor.second - 1}))) {
      shared_ptr<Move> m{
          new Move{coor, {coor.first + 2, coor.second - 1}, ' '}};
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
        validMoves.emplace_back(m);
      }
    }
    if (coor.second + 1 <= 7 &&
        (!eyes->isOccupied({coor.first + 2, coor.second + 1}) ||
         eyes->isOpponent({coor.first + 2, coor.second + 1}))) {
      shared_ptr<Move> m{
          new Move{coor, {coor.first + 2, coor.second + 1}, ' '}};
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
        validMoves.emplace_back(m);
      }
    }
  }

  return validMoves;
}

char Knight::getType() const {
  return getPlayer() == 0 ? 'N' : 'n';
}
