#ifndef GAME_H
#define GAME_H
#include "gameboard.h"
#include "human.h"
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"

using namespace std;

class Game {
    GameBoard *board;

    public:
    Game() = default;
    ~Game() = default;
    void play();
    bool isValidCmd() const;
};

#endif