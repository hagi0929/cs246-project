#include "Player.h"

class Computer1 : public Player {
    public:
        Computer1(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore() const;
}