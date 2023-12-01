#include "queen.h"
using namespace std;

Queen::Queen(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Queen::possibleMoves() const
{
  vector<shared_ptr<Move>> validMoves;

  // Directions: up, down, left, right, and diagonals
  pair<int, int> directions[8] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

  for (auto &dir : directions)
  {
    pair<int, int> nextCoor = coor;

    while (true)
    {
      nextCoor.first += dir.first;
      nextCoor.second += dir.second;

      if (nextCoor.first < 0 || nextCoor.first >= 8 ||
          nextCoor.second < 0 || nextCoor.second >= 8)
      {
        break;
      }

      if (eyes->isOccupied(nextCoor))
      {
        if (eyes->isOpponent(nextCoor))
        {
          validMoves.emplace_back(make_shared<Move>(coor, nextCoor, ' '));
        }
        break;
      }

      validMoves.emplace_back(make_shared<Move>(coor, nextCoor, ' '));
    }
  }

  return validMoves;
}

char Queen::getType() const
{
  return getPlayer() == 0 ? 'Q' : 'q';
}
