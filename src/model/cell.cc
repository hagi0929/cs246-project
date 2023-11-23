#include "cell.h"

using namespace std;

Cell::Cell() : piece{nullptr} {
    dout << "Cell ctor is called" << endl;
}

Cell::~Cell() {delete piece;}

shared_ptr<Piece> Cell::getPiece() {
    return nullptr;
}

bool Cell::isEmpty() {
    return true;
}

void Cell::setPiece(shared_ptr<Piece> p) {
    piece = p;
}

void Cell::removePiece() {
    piece = nullptr;
}

void Cell::notifyDisplay() {
    // TODO
}
