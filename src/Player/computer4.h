#ifndef COMPUTER4_H
#define COMPUTER4_H
#include "player.h"

class Computer4 : public Player {
    public:
        Computer4(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore() const;
};

#endif