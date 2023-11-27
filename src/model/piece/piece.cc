#include "piece.h"
using namespace std;

Piece::Piece(Color color, int row, int col, int moveCount, shared_ptr<Eyes> eyes) :
             color{color}, row{row}, col{col}, moveCount{moveCount}, eyes{eyes} {
  cout << "Piece ctor is called" << endl;
}

Color Piece::getColor() const {
  return color;
}
