#include "queen.h"
using namespace std;

Queen::Queen(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Queen::possibleMoves() const
{
  cout << "Queen possibleMoves() is called" << endl;
  vector<shared_ptr<Move>> validMoves;
}

char Queen::getType() const
{
  cout << "Queen getType() is called" << endl;
  return getPlayer() == 0 ? 'Q' : 'q';
}
