#include "Player.h"

class Human : public Player {
    public:
        Human(GameBoard &gameBoard);
        Turn getNextTurn();
        int getScore()   const;
}