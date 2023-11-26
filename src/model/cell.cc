#include "cell.h"

using namespace std;

Cell::Cell(int row, int col) : piece{nullptr}, row{row}, col{col} {
    cout << "Cell ctor is called" << endl;
}
Cell::~Cell() {};

shared_ptr<Piece> Cell::getPiece() {
    return nullptr;
}

int Cell::getRow() const {
    return row;
}

int Cell::getCol() const {
    return col;
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

void Cell::notifyObservers() {
    for (auto ob : observers) ob->notify(*this);
}
