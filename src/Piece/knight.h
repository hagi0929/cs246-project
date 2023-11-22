#include "Piece.h"
using namespace std;

class Knight : public Piece {
 public:
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};
