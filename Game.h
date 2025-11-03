#ifndef GAME_H
#define GAME_H

#include "Stock.h"
#include "Player.h"

class Game {
private:
    Stock stock;
    Player player;
    int maxTurns;
    int currentTurn;

    void displayStatus();
    void displayFinalResults();
    int getPlayerAction();

public:
    Game();
    void run();
};

#endif
