#include "piece.h"
using namespace std;

class Knight : public Piece {
 public:
  Knight(int team, int moveCount) : Piece{Piece{team, moveCount}}, type{PieceType::Knight} {
    dout << "Knight ctor called" << endl;
  }
  PieceType getType() {
    return PieceType::Queen;
  };
  vector<Coor> possibleMoves(Coor c) {
    return {};
  };
};