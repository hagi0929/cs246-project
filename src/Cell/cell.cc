#include "cell.h"

Cell::Cell() : piece{nullptr} {
    //
}
Cell::~Cell() {delete piece;}

Piece Cell::getPiece() {
    return {};
};
bool Cell::isEmpty() {
    return true;
};