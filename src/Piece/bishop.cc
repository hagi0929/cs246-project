#include "Piece.h"
using namespace std;

class Bishop : public Piece {
 public:
 Bishop(int team, int moveCount) : Piece{Piece}, PieceType{PieceType::Bishop} {
  dout << "Bishop ctor called" << endl;
 }
  PieceType getType() {
    return PieceType::Queen;
  };
  vector<Coor> possibleMoves(Coor c) {
    return {};
  };
};