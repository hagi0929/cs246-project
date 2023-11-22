#include "Piece.h"
using namespace std;

class Rook : public Piece {
 public:
 Rook(int team, int moveCount) : Piece{Piece}, PieceType{PieceType::Rook} {
  dout << "Rook ctor called" << endl;
 }
  PieceType getType() {
    return PieceType::Queen;
  };
  vector<Coor> possibleMoves(Coor c) {
    return {};
  };
};