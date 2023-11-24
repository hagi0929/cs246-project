#ifndef COMPUTER1_H
#define COMPUTER1_H
#include "player.h"
using namespace std;
class Computer1 : public Player {
        GameBoard *board;
    public:
        Computer1(GameBoard *board);
        Turn &getNextTurn();
        int getScore() const;
};
#endif