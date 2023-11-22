#include "Player.h"

class Computer3 : public Player {
    public:
        Computer3(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore() const;
}