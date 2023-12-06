#ifndef VIEW_H
#define VIEW_H

#include "observer.h"

class View : public Observer
{
protected:
    int boardSize = 8;

public:
    virtual void display() = 0;
    virtual void notify(Cell &c) = 0;
    int getBoardSize() const;
};

#endif
