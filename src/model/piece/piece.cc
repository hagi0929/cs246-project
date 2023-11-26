#include "piece.h"
using namespace std;

Piece::Piece(Color color, int row, int col, int moveCoun, shared_ptr<Eyes>) :
             color{color}, row{row}, col{col}, moveCount{moveCount}, eyes{eyes} {
  cout << "Piece ctor is called" << endl;
}

Color Piece::getColor() const {
  return color;
}
