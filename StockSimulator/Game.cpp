#include "Game.h"
#include <iostream>
#include <iomanip>

Game::Game(double initialBalance, double initialStockPrice, int totalDays)
    : player(initialBalance), stock(initialStockPrice) {
    currentDay = 1;
    maxDays = totalDays;
}

void Game::start() {
    std::cout << "========================================" << std::endl;
    std::cout << "    BIRŽOS SIMULIATORIUS" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Tikslas: Maksimizuoti turtą per " << maxDays << " dienas!" << std::endl;
    std::cout << std::endl;

    while (!isGameOver()) {
        processTurn();
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "         ŽAIDIMAS BAIGTAS!" << std::endl;
    std::cout << "========================================" << std::endl;

    double finalNetWorth = player.getNetWorth(stock.getCurrentPrice());
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Galutinė vertė: " << finalNetWorth << " EUR" << std::endl;

    if (player.isBankrupt(stock.getCurrentPrice())) {
        std::cout << "Rezultatas: BANKROTAS!" << std::endl;
    } else if (finalNetWorth > 1000.0) {
        std::cout << "Rezultatas: PELNAS! +" << (finalNetWorth - 1000.0) << " EUR" << std::endl;
    } else {
        std::cout << "Rezultatas: NUOSTOLIS! " << (finalNetWorth - 1000.0) << " EUR" << std::endl;
    }
}

void Game::processTurn() {
    if (currentDay > 1) {
        stock.updatePrice();
    }

    displayStats();
    displayMenu();

    char choice;
    std::cout << "Jūsų pasirinkimas: ";
    std::cin >> choice;

    double currentPrice = stock.getCurrentPrice();

    switch (choice) {
        case 'P':
        case 'p': {
            int amount;
            std::cout << "Kiek akcijų pirkti? ";
            std::cin >> amount;

            if (player.buyShares(amount, currentPrice)) {
                std::cout << "✓ Nupirkta " << amount << " akcijų po " << currentPrice << " EUR" << std::endl;
            } else {
                std::cout << "✗ Nepakanka pinigų!" << std::endl;
            }
            break;
        }
        case 'A':
        case 'a': {
            int amount;
            std::cout << "Kiek akcijų parduoti? ";
            std::cin >> amount;

            if (player.sellShares(amount, currentPrice)) {
                std::cout << "✓ Parduota " << amount << " akcijų po " << currentPrice << " EUR" << std::endl;
            } else {
                std::cout << "✗ Neturite tiek akcijų!" << std::endl;
            }
            break;
        }
        case 'L':
        case 'l':
            std::cout << "Laukiate..." << std::endl;
            break;
        default:
            std::cout << "Neteisingas pasirinkimas! Laukiate..." << std::endl;
    }

    std::cout << std::endl;
    currentDay++;
}

bool Game::isGameOver() const {
    return (currentDay > maxDays) || player.isBankrupt(stock.getCurrentPrice());
}

void Game::displayStats() const {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Diena: " << currentDay << "/" << maxDays << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Akcijos kaina: " << stock.getCurrentPrice() << " EUR" << std::endl;
    std::cout << "Jūsų balansas: " << player.getBalance() << " EUR" << std::endl;
    std::cout << "Turimų akcijų: " << player.getSharesOwned() << std::endl;
    std::cout << "Bendra vertė: " << player.getNetWorth(stock.getCurrentPrice()) << " EUR" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void Game::displayMenu() const {
    std::cout << "[P] Pirkti  [A] pArduoti  [L] Laukti" << std::endl;
}