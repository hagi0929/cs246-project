#include <memory>

#include "coor.h"
class Piece;
class Move {
  Coor from;
  Coor to;
  std::shared_ptr<Piece> captured;

 public:
  Move(Coor from, Coor to, std::shared_ptr<Piece> captured = nullptr);
  Coor getFrom() const;
  Coor getTo() const;
  int getPlayer() const;
  std::shared_ptr<Piece> getCaptured() const;
  friend std::ostream &operator<<(std::ostream &out, const Move &move);
  bool operator==(const Move &other) const;
};

class PromotionMove {

}

class CaptureMove {

}

class CastlingMove {

}

class EnPassantMove {
  
}