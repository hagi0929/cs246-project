#include "piece.h"
using namespace std;

class Queen : public Piece {
 public:
  Queen(int team, int moveCount) : Piece{Piece{team, moveCount}}, type{PieceType::Queen} {
    dout << "Queen ctor called" << endl;
  }
  PieceType getType() {
    return PieceType::Queen;
  };
  vector<Coor> possibleMoves(Coor c) {
    return {};
  };
};