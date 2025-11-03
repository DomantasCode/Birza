#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock {
private:
    std::string name;
    double price;
    double minPrice;
    double maxPrice;

public:
    Stock(const std::string& stockName, double initialPrice);

    void updatePrice();
    double getPrice() const;
    std::string getName() const;
};

#endif

