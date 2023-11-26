#include "queen.h"
using namespace std;

vector<unique_ptr<Move>> Queen::possibleMoves() const {
  cout << "Queen possibleMoves() is called" << endl;
  return {};
}

char Queen::getType() const { 
  cout << "Queen getType() is called" << endl;
  return color == Color::White ? 'Q' : 'q';
}

void Queen::movePiece(Move &m) {
  cout << "Queen movePiece() is called" << endl;
}
