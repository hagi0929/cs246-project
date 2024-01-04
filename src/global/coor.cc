#include "coor.h"

Coor::Coor(int row, int col) : row{row}, col{col} {}
Coor::Coor(std::string s) : col{s[0] - 'a'}, row{7 - s[1] + '1'} {}
int Coor::getRow() const { return row; }
int Coor::getCol() const { return col; }
std::ostream& operator<<(std::ostream& out, const Coor& coor) {
  out << (char)(coor.col + 'a') << (char)((7 - coor.row) + '1');
  return out;
}

bool Coor::operator==(const Coor& other) const {
  return col == other.col && row == other.row;
}

Coor Coor::operator+(const Coor& other) const {
  return Coor{row + other.row, col + other.col};
}

Coor Coor::operator-(const Coor& other) const {
  return Coor{row - other.row, col - other.col};
}

bool Coor::isInbound() const {
  return col >= 0 && col < 8 && row >= 0 && row < 8;
}