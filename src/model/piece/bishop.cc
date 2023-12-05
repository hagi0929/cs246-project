#include "bishop.h"
using namespace std;

Bishop::Bishop(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Bishop::possibleMoves(bool checkSafety) const {
  vector<shared_ptr<Move>> validMoves;

  // Diagonal directions: top-left, top-right, bottom-left, bottom-right
  pair<int, int> directions[4] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
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

char Bishop::getType() const { return getPlayer() == 0 ? 'B' : 'b'; }
