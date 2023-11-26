#ifndef CELL_H
#define CELL_H

#include "observer.h"


class Display: public Observer {
    int boardSize = 8;

    public :
    virtual void display() = 0;
    int getBoardSize();
};

#endif
