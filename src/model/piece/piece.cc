#include "piece.h"
using namespace std;

Piece::Piece(pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes)
    : coor{coor}, player{player}, eyes{eyes} {}

int Piece::getPlayer() const { return player; }

pair<int, int> Piece::getCoor() const {
    return coor;
}

void Piece::addMove() { ++moveCount; }

void Piece::setCoor(pair<int, int> c) { coor = c; }
