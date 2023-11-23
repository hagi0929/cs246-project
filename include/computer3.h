#ifndef COMPUTER3_H
#define COMPUTER3_H
#include "player.h"
using namespace std;
class Computer3 : public Player {
    public:
        Computer3(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore() const;
};

#endif