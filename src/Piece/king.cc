#include "piece.h"
using namespace std;

class King : public Piece {
 public:
 King(int team, int moveCount) : Piece{Piece}, PieceType{PieceType::King} {
  dout << "King ctor called" << endl;
 }
  PieceType getType() {
    return PieceType::Queen;
  };
  vector<Coor> possibleMoves(Coor c) {
    return {};
  };
};