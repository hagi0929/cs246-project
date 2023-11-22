#include "Piece.h"
using namespace std;

class Queen : public Piece {
 public:
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};
