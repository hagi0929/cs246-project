#include "king.h"
using namespace std;

King::King (int team, int moveCount) : Piece{team, moveCount} {
  dout << "King ctor is called" << endl;
}

char King::getChar() const {
  return team == 1 ? 'K' : 'k';
}

PieceType King::getType() const { 
  dout << "King getType is called" << endl;
  return PieceType::King;
}
vector<Coor> King::possibleMoves(Coor c) const { return {}; }
