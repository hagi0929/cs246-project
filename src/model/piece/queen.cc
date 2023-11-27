#include "queen.h"
using namespace std;

vector<shared_ptr<Move>> Queen::possibleMoves() const {
  cout << "Queen possibleMoves() is called" << endl;
  vector<shared_ptr<Move>> validMoves;
  return validMoves;
}

char King::getType() const { 
  cout << "King getType() is called" << endl;
  return color == Color::White ? 'K' : 'k';
}
