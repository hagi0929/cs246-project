#include "king.h"
using namespace std;

King::King (int team, int moveCount) : Piece{team, moveCount} {
  cout << "King ctor is called" << endl;
}
PieceType King::getType() const { 
  cout << "King getType is called" << endl;
  return PieceType::King; }
vector<Coor> King::possibleMoves(Coor c) const { return {}; }
