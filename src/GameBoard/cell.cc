#include "cell.h"

using namespace std;

Cell::Cell() : piece{nullptr} {
    dout << "Cell ctor is called" << endl;
}

Cell::~Cell() {delete piece;}

Piece Cell::getPiece() {
    return nullptr;
}

bool Cell::isEmpty() {
    return true;
}

void Cell::setPiece(Piece *p) {
    piece = p;
}

void Cell::removePiece() {
    delete piece;
    piece = nullptr;
}

void Cell::notifyDisplay() {
    // TODO
}
