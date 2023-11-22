#include "Player.h"

class Computer4 : public Player {
    public:
        Computer4(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore() const;
}