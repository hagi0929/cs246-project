#include "piece.h"
using namespace std;

Piece::Piece(int team, int moveCount) : team{team}, moveCount{moveCount} {
  dout << "Piece ctor is called" << endl;
}

int Piece::getTeam() const {
  return team;
};
