#ifndef STOCK_H
#define STOCK_H


class Stock {
private:
    double currentPrice;
public:
    Stock(double initialPrice);

    void updatePrice();

    double getCurrentPrice() const;
};



#endif
