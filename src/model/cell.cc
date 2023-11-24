#include "cell.h"

using namespace std;

Cell::Cell(Coor coor) : piece{nullptr}, coor{coor} {
  dout << "Cell ctor is called" << endl;
}

shared_ptr<Piece> Cell::getPiece() {
  return piece;
}

bool Cell::isEmpty() {
  return !piece;
}

void Cell::setPiece(shared_ptr<Piece> p) {
  piece = p;
}

void Cell::attach(unique_ptr<Observer> ob) {
  for(auto &obs: observers) {
    if(!obs) {
        obs = move(ob);
        break;
    }
  }
}

void Cell::detach(unique_ptr<Observer> ob) {
  for (auto &obs : observers) {
    if (obs) {
      obs = nullptr;
    }
  }
}

int Cell::getRow() const {
  return coor.y;
}

int Cell::getCol() const {
    return coor.x;
}
void Cell::removePiece() {
  piece = nullptr;
}

void Cell::notifyDisplay() {
  for (int i = 0; i < observerCount; ++i) {
    observers[i]->notify(*this);
  }
}
