#ifndef DISPLAY_H
#define DISPLAY_H

#include "observer.h"

class Display : public Observer
{
    int boardSize = 8;

public:
    virtual void display() = 0;
    virtual void notify(Cell &c) = 0;
    int getBoardSize() const;
};

#endif
