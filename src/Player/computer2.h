#include "Player.h"

class Computer2 : public Player {
    public:
        Computer2(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore() const;
}