#include "piece.h"
#include "snapshot.h"

class Pawn : public Piece {
 public:
  Pawn(Coor coor, int player, int moveCount = 0);
  Pawn(Piece* other);
  Pawn(Pawn& other);

  std::vector<Move> possibleMoves(Snapshot& eye,
                                  bool safetyCheck = true) const override;
  std::shared_ptr<Piece> clone() override;
  char getType() const override;
  void setCoor(Coor newCoor) override;
};