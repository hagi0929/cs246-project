#include "queen.h"
using namespace std;

Queen::Queen (int team, int moveCount) : Piece{team, moveCount} {
  dout << "King ctor is called" << endl;
}
PieceType Queen::getType() const { 
  dout << "Queen getType is called" << endl;
  return PieceType::Queen; }
vector<Coor> Queen::possibleMoves(Coor c) const { return {}; }
