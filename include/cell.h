#ifndef CELL_H
#define CELL_H

#include"piece.h"

class Cell {
    Piece *piece;
    public:
    Cell();
    ~Cell();
    Piece getPiece();
    bool isEmpty();
};

#endif
