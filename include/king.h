#include "eye.h"
#include "piece.h"

class King : public Piece {
 public:
  King(Coor coor, int player);
  King(Piece&& other);
  King(Piece& other);
  std::vector<Move> possibleMoves(Eye& eye,
                                  bool safetyCheck = true) const override;
  std::shared_ptr<Piece> clone() const override;
  char getType() const override;
};