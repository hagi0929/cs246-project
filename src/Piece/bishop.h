#include "Piece.h"
#include <vector>
using namespace std;

class Bishop : public Piece {
 public:
 Bishop();
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};
