#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
using namespace std;
class Human : public Player {
    public:
        Human();
        ~Human();
        Turn &getNextTurn() override;
};

#endif