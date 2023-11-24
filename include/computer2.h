#ifndef COMPUTER2_H
#define COMPUTER2_H
#include "player.h"

using namespace std;

class Computer2 : public Player {
        GameBoard *board;
    public:
        Computer2(GameBoard *board);
        Turn &getNextTurn();
        int getScore() const;
};

#endif