#include "piece.h"
using namespace std;

Piece::Piece(int team, int moveCount) : team{team}, moveCount{moveCount} {
  cout << "Piece ctor is called" << endl;
}

int Piece::getTeam() const {
  return team;
};
