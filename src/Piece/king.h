#include "Piece.h"

class King : public Piece {
 public:
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};
