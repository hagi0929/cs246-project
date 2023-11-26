#include "king.h"
using namespace std;

vector<unique_ptr<Move>> King::possibleMoves() const {
  cout << "King possibleMoves() is called" << endl;
  return {};
}

char King::getType() const { 
  cout << "King getType() is called" << endl;
  return color == Color::White ? 'K' : 'k';
}

void King::movePiece(Move &m) {
  cout << "King movePiece() is called" << endl;
}
