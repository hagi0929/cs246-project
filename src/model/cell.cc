#include "cell.h"

#include "piece.h"

using namespace std;

Cell::Cell(pair<int, int> coor) : piece{nullptr}, coor{coor} {}
Cell::~Cell(){};

shared_ptr<Piece> Cell::getPiece() { return piece; }

int Cell::getRow() const { return coor.first; }

int Cell::getCol() const { return coor.second; }

bool Cell::isEmpty() { return piece == nullptr; }

void Cell::setPiece(shared_ptr<Piece> p)
{
  piece = p;
  piece->setCoor(coor);
  notifyObservers();
}

void Cell::removePiece()
{
  piece = nullptr;
  notifyObservers();
}

void Cell::notifyObservers()
{
  for (auto ob : observers)
    ob->notify(*this);
}
