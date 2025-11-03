#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    double balance;
    int stocksOwned;
    const double startingBalance;

public:
    Player();

    bool buyStock(double price);
    bool sellStock(double price);

    double getBalance() const;
    int getStocksOwned() const;
    double getTotalValue(double currentStockPrice) const;
    double getProfitLoss() const;
    bool isBankrupt() const;
};

#endif
