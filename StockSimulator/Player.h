#ifndef PLAYER_H
#define PLAYER_H

//const reiškia: "šis metodas NEKEIČIA objekto būsenos, tik skaito duomenis"

class Player {
private:
    double balance;
    int sharesOwned;

public:
    Player(double initialBalance);

    bool buyShares(int amount, double pricePerShare);

    bool sellShares(int amount, double pricePerShare);

    double getNetWorth(double currentStockPrice) const;

    double getBalance() const;
    int getSharesOwned() const;

    bool isBankrupt(double currentStockPrice) const;
};



#endif
