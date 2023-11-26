#ifndef COMPUTER3_H
#define COMPUTER3_H
#include "player.h"
#include "move.h"

using namespace std;
class Computer3 : public Player {
        GameBoard *board;
    public:
        Computer3(GameBoard *board);
        Move &getNextTurn();
        int getScore() const;
};

#endif