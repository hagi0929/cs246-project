#include <vector>
#include <iostream>
using namespace std;

enum class PieceType { King, Queen, Knight, Bishop, Rook, Pawn };

struct Coor {
  int x;
  int y;
};

class Piece {
  int team;
  int moveCount;
  PieceType type;

 public:
  Piece(int team, int moveCount);
  int getTeam() const;
  virtual PieceType getType() const = 0;
  virtual vector<Coor> possibleMoves(Coor c) const = 0;
};
