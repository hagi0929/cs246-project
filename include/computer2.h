#ifndef COMPUTER2_H
#define COMPUTER2_H
#include "player.h"
#include "move.h"

using namespace std;

class Computer2 : public Player {
        GameBoard *board;
    public:
        Computer2(GameBoard *board);
        Move &getNextTurn();
        int getScore() const;
};

#endif