#include "snapshot.h"
#include "piece.h"

class King : public Piece {
 public:
  King(Coor coor, int player, int moveCount = 0);
  King(Piece* other);
  King(King& other);
  
  std::vector<Move> possibleMoves(Snapshot& eye,
                                  bool safetyCheck = true) const override;
  std::shared_ptr<Piece> clone() override;
  char getType() const override;
  int getValue() const override;
};