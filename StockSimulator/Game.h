#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Stock.h"

class Game {
private:
    Player player;
    Stock stock;
    int currentDay;
    int maxDays;

public:
    Game(double initialBalance, double initialStockPrice, int totalDays);

    void start();

    void processTurn();

    bool isGameOver() const;

    void displayStats() const;

    void displayMenu() const;
};

#endif

