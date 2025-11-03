#include "Stock.h"
#include <cstdlib>
#include <ctime>

Stock::Stock(const std::string& stockName, double initialPrice)
    : name(stockName), price(initialPrice), minPrice(10.0), maxPrice(500.0) {
}

void Stock::updatePrice() {
    // Atsitiktinis kainos pokytis nuo -10% iki +10%
    double change = (rand() % 21 - 10) / 100.0; // -0.10 iki 0.10
    price = price * (1.0 + change);

    // Ribojam kainą
    if (price < minPrice) price = minPrice;
    if (price > maxPrice) price = maxPrice;
}

double Stock::getPrice() const {
    return price;
}

std::string Stock::getName() const {
    return name;
}
