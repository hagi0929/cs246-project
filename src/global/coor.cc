#include "coor.h"

Coor::Coor(int x, int y) : x{x}, y{y} {}
Coor::Coor(std::string s) : x{s[0] - 'a'}, y{s[1] - '1'} {}
int Coor::getX() const { return x; }
int Coor::getY() const { return y; }
std::ostream& operator<<(std::ostream& out, const Coor& coor) {
  out << (char)(coor.x + 'a') << (char)(coor.y + '1');
  return out;
}

bool Coor::operator==(const Coor& other) const {
  return x == other.x && y == other.y;
}

Coor Coor::operator+(const Coor& other) const {
  return Coor{x + other.x, y + other.y};
}

Coor Coor::operator-(const Coor& other) const {
  return Coor{x - other.x, y - other.y};
}

bool Coor::isInbound() const {
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}