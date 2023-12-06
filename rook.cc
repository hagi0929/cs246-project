#include "rook.h"

using namespace std;

Rook::Rook(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Rook::possibleMoves(bool checkSafety) const {
  vector<shared_ptr<Move>> validMoves;

  pair<int, int> directions[8] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1},
                                  {0, -1},  {0, 1},  {1, 0},  {-1, 0}};
  for (auto dir : directions) {
    pair<int, int> nextCoor = coor;
    while (true) {
      nextCoor.first += dir.first;
      nextCoor.second += dir.second;

      if (nextCoor.first < 0 || nextCoor.first >= 8 || nextCoor.second < 0 ||
          nextCoor.second >= 8) {
        break;
      }

      if (eyes->isOccupied(nextCoor)) {
        if (eyes->isOpponent(nextCoor)) {
          shared_ptr<Move> m = make_shared<Move>(coor, nextCoor, ' ');
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety)
            validMoves.emplace_back(m);
        }
        break;
      }

      shared_ptr<Move> m = make_shared<Move>(coor, nextCoor, ' ');
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety)
        validMoves.emplace_back(m);
    }
  }
  return validMoves;
}

char Rook::getType() const { return getPlayer() == 0 ? 'R' : 'r'; }
