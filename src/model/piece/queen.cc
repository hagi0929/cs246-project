#include "queen.h"
using namespace std;

Queen::Queen(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Queen::possibleMoves(bool checkSafety) const {
  vector<shared_ptr<Move>> validMoves;

  // Directions: up, down, left, right, and diagonals
  pair<int, int> directions[8] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1},
                                  {0, -1},  {0, 1},  {1, 0},  {-1, 0}};
  for (auto dir : directions) {
    pair<int, int> nextCoor = coor;
    while (true) {
      nextCoor.first += dir.first;
      nextCoor.second += dir.second;

      // Check if the next coordinate is within the board boundaries
      if (nextCoor.first < 0 || nextCoor.first >= 8 || nextCoor.second < 0 ||
          nextCoor.second >= 8) {
        break;
      }

      // Check if the next cell is occupied
      if (eyes->isOccupied(nextCoor)) {
        // If occupied by an opponent, add as a valid move, then break
        if (eyes->isOpponent(nextCoor)) {
          shared_ptr<Move> m = make_shared<Move>(coor, nextCoor, ' ');
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety)
            validMoves.emplace_back(m);
        }
        break;
      }

      // Add the move if the cell is not occupied
      shared_ptr<Move> m = make_shared<Move>(coor, nextCoor, ' ');
      if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety)
        validMoves.emplace_back(m);
    }
  }

  return validMoves;
}

char Queen::getType() const { return getPlayer() == 0 ? 'Q' : 'q'; }
