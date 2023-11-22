#include "Piece.h"
using namespace std;

class Queen : public Piece {
 public:
 Queen(int team, int moveCount) : Piece{Piece}, PieceType{PieceType::Queen} {
  dout << "Queen ctor called" << endl;
 }
  PieceType getType() {
    return PieceType::Queen;
  };
  vector<Coor> possibleMoves(Coor c) {
    return {};
  };
};