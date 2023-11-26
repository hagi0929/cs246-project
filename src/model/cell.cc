#include "cell.h"

using namespace std;

Cell::Cell() : piece{nullptr} { cout << "Cell ctor is called" << endl; }

Cell::~Cell() { cout << "Cell dtor is called" << endl; }

shared_ptr<Piece> Cell::getPiece() { return nullptr; }

bool Cell::isEmpty() { return true; }

void Cell::setPiece(shared_ptr<Piece> p) { piece = p; }

void Cell::removePiece() { piece = nullptr; }

void Cell::notifyDisplay() {
  // TODO
}
