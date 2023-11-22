#include "Piece.h"
using namespace std;

class Pawn : public Piece {
 public:
 Pawn(int team, int moveCount) : Piece{Piece}, PieceType{PieceType::Pawn} {
  dout << "Pawn ctor called" << endl;
 }
  PieceType getType() {
    return PieceType::Queen;
  };
  vector<Coor> possibleMoves(Coor c) {
    return {};
  };
};