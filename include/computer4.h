#ifndef COMPUTER4_H
#define COMPUTER4_H
#include "player.h"
using namespace std;
class Computer4 : public Player {
        GameBoard *board;
    public:
        Computer4(GameBoard *board);
        Turn &getNextTurn();
        int getScore() const;
};

#endif