#ifndef GAME_H
#define GAME_H
#include"gameboard.h"
using namespace std;
class Game {
    GameBoard *currentGame;

    public:
    Game();
    ~Game();
    void play();
    bool isValidCmd();
};

#endif