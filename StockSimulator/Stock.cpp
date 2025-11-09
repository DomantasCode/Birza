#include "Stock.h"
#include <cstdlib>
#include <ctime>

/*rand() % 31 = 0 → 0 - 15 = -15 (kaina krenta 15€)
rand() % 31 = 15 → 15 - 15 = 0 (kaina nekinta)
rand() % 31 = 30 → 30 - 15 = +15 (kaina kyla 15€)
*/

Stock::Stock(double initialPrice) {
    currentPrice = initialPrice;
    srand(time(0));
}

void Stock::updatePrice() {
    int change = (rand() % 31) - 15;
    currentPrice += change;

    if (currentPrice < 10) {
        currentPrice = 10;
    }
}

double Stock::getCurrentPrice() const {
    return currentPrice;
}
