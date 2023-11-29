#include "piece.h"
using namespace std;

Piece::Piece(pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes)
    : coor{coor}, player{player}, eyes{eyes} {}

int Piece::getPlayer() const { return player; }

void Piece::addMove() { ++moveCount; }

void Piece::setCoor(pair<int, int> coor) { coor = coor; }
