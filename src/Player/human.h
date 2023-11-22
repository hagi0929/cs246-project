#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human : public Player {
    public:
        Human(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore()   const;
};

#endif