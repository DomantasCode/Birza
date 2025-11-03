#include "Player.h"

Player::Player() : balance(1000.0), stocksOwned(0), startingBalance(1000.0) {
}

bool Player::buyStock(double price) {
    if (balance >= price) {
        balance -= price;
        stocksOwned++;
        return true;
    }
    return false;
}

bool Player::sellStock(double price) {
    if (stocksOwned > 0) {
        balance += price;
        stocksOwned--;
        return true;
    }
    return false;
}

double Player::getBalance() const {
    return balance;
}

int Player::getStocksOwned() const {
    return stocksOwned;
}

double Player::getTotalValue(double currentStockPrice) const {
    return balance + (stocksOwned * currentStockPrice);
}

double Player::getProfitLoss() const {
    return balance - startingBalance;
}

bool Player::isBankrupt() const {
    return balance <= 0 && stocksOwned == 0;
}
