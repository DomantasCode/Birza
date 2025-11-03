#include "Game.h"
#include <iostream>
#include <iomanip>

Game::Game() : stock("TECH", 100.0), maxTurns(20), currentTurn(1) {
}

void Game::displayStatus() {
    std::cout << "\n========================================\n";
    std::cout << "EILE: " << currentTurn << "/" << maxTurns << "\n";
    std::cout << "========================================\n";
    std::cout << "Akcija: " << stock.getName() << "\n";
    std::cout << "Kaina: $" << std::fixed << std::setprecision(2) << stock.getPrice() << "\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Jusu balansas: $" << player.getBalance() << "\n";
    std::cout << "Turimos akcijos: " << player.getStocksOwned() << "\n";
    std::cout << "Bendra verte: $" << player.getTotalValue(stock.getPrice()) << "\n";
    std::cout << "========================================\n";
}

void Game::displayFinalResults() {
    std::cout << "\n\n****************************************\n";
    std::cout << "       ZAIDIMAS BAIGTAS!\n";
    std::cout << "****************************************\n";
    std::cout << "Galutinis balansas: $" << std::fixed << std::setprecision(2)
              << player.getBalance() << "\n";
    std::cout << "Likusios akcijos: " << player.getStocksOwned() << "\n";
    std::cout << "Bendra verte: $" << player.getTotalValue(stock.getPrice()) << "\n";

    double profitLoss = player.getTotalValue(stock.getPrice()) - 1000.0;
    std::cout << "----------------------------------------\n";

    if (profitLoss > 0) {
        std::cout << "PELNAS: +$" << profitLoss << "\n";
        std::cout << "Sveikiname! Jusu pelnas!\n";
    } else if (profitLoss < 0) {
        std::cout << "NUOSTOLIS: $" << profitLoss << "\n";
        std::cout << "Deja, praradote pinigu.\n";
    } else {
        std::cout << "Nei pelno, nei nuostolio.\n";
    }
    std::cout << "****************************************\n";
}

int Game::getPlayerAction() {
    std::cout << "\nPasirinkite veiksma:\n";
    std::cout << "1 - PIRKTI akcija\n";
    std::cout << "2 - PARDUOTI akcija\n";
    std::cout << "3 - LAUKTI (praleisti eile)\n";
    std::cout << "Jusu pasirinkimas: ";

    int action;
    std::cin >> action;

    while (action < 1 || action > 3) {
        std::cout << "Neteisingas pasirinkimas! Iveskite 1, 2 arba 3: ";
        std::cin >> action;
    }

    return action;
}

void Game::run() {
    std::cout << "========================================\n";
    std::cout << "  AKCIJU RINKOS SIMULIATORIUS\n";
    std::cout << "========================================\n";
    std::cout << "Pradinis balansas: $1000\n";
    std::cout << "Eilu skaicius: " << maxTurns << "\n";
    std::cout << "Tikslas: Uzdirbti kuo daugiau pinigu!\n";
    std::cout << "========================================\n";

    while (currentTurn <= maxTurns && !player.isBankrupt()) {
        displayStatus();

        int action = getPlayerAction();

        switch (action) {
            case 1: // PIRKTI
                if (player.buyStock(stock.getPrice())) {
                    std::cout << "\n>>> Nusipirkote 1 akcija uz $"
                              << std::fixed << std::setprecision(2)
                              << stock.getPrice() << "\n";
                } else {
                    std::cout << "\n>>> Nepakanka pinigu pirkimui!\n";
                }
                break;

            case 2: // PARDUOTI
                if (player.sellStock(stock.getPrice())) {
                    std::cout << "\n>>> Pardavete 1 akcija uz $"
                              << std::fixed << std::setprecision(2)
                              << stock.getPrice() << "\n";
                } else {
                    std::cout << "\n>>> Neturite akciju pardavimui!\n";
                }
                break;

            case 3: // LAUKTI
                std::cout << "\n>>> Praleidziate eile...\n";
                break;
        }

        // Atnaujinti akcijos kainą kitam žaidimo ėjimui
        stock.updatePrice();
        currentTurn++;
    }

    if (player.isBankrupt()) {
        std::cout << "\n\n!!! BANKROTAS !!! Praradote visus pinigus ir akcijas!\n";
    }

    displayFinalResults();
}
