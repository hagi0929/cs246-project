#include <string>

struct Coor {
  int x;
  int y;
};

class Move {
    Coor cur, dest;
    std::string promotion;

    public:
    Move(Coor cur, Coor dest, string promotion);
    Coor getCur() const;
    Coor getDest() const;
};