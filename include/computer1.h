#ifndef COMPUTER1_H
#define COMPUTER1_H
#include "player.h"

class Computer1 : public Player {
    public:
        Computer1(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore() const;
}
#endif