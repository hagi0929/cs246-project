#include "queen.h"
using namespace std;

Queen::Queen (int team, int moveCount) : Piece{team, moveCount} {
  cout << "King ctor is called" << endl;
}
PieceType Queen::getType() const { 
  cout << "Queen getType is called" << endl;
  return PieceType::Queen; }
vector<Coor> Queen::possibleMoves(Coor c) const { return {}; }
