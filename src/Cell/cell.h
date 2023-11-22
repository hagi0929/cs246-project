#ifndef CELL_H
#define CELL_H

#include "../Piece/piece.h"

class Cell {
    Piece *piece;
    public:
    Cell();
    ~Cell();
    Piece getPiece();
    bool isEmpty();
};

#endif
