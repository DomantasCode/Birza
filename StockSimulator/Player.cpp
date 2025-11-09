#include "Player.h"

Player::Player(double initialBalance) {
    balance = initialBalance;
    sharesOwned = 0;
}

bool Player::buyShares(int amount, double pricePerShare) {
    double totalCost = amount * pricePerShare;

    if  (totalCost > balance) {
        return false;
    }

    balance -= totalCost;
    sharesOwned += amount;
    return true;
}

bool Player::sellShares(int amount, double pricePerShare) {

    if (amount > sharesOwned) {
        return false;
    }

    double totalRevenue = amount * pricePerShare;
    balance += totalRevenue;
    sharesOwned -= amount;
    return true;
}

double Player::getNetWorth(double currentStockPrice) const {
    double stockValue = sharesOwned * currentStockPrice;
    return balance + stockValue;
}

double Player::getBalance() const {
    return balance;
}

int Player::getSharesOwned() const {
    return sharesOwned;
}

bool Player::isBankrupt(double currentStockPrice) const {
    return (balance <= 0 && sharesOwned == 0);
}
