#include "coor.h"

Coor::Coor(int x, int y) : x{x}, y{y} {}
Coor::Coor(std::string s) : x{s[0] - 'a'}, y{s[1] - '1'} {}
int Coor::getX() { return x; }
int Coor::getY() { return y; }
std::ostream& operator<<(std::ostream& out, const Coor& coor) {
  out << (char)(coor.x + 'a') << (char)(coor.y + '1');
  return out;
}
