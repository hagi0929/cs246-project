#ifndef COMPUTER2_H
#define COMPUTER2_H
#include "player.h"

class Computer2 : public Player {
    public:
        Computer2(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore() const;
};

#endif