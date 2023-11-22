#include "Piece.h"

class Rook : public Piece {
 public:
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};
