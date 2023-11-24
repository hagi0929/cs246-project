#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <iostream>
#include "coor.h"
using namespace std;

enum class PieceType { King, Queen, Knight, Bishop, Rook, Pawn };

class Piece {
 protected:
  int team;
  int moveCount;

 public:
  Piece(int team, int moveCount);
  int getTeam() const;
  virtual char getChar() const = 0;
  virtual PieceType getType() const = 0;
  virtual vector<Coor> possibleMoves(Coor c) const = 0;
};

#endif
