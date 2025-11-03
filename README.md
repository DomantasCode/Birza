# Biržos Mini-Simuliatorius 📈

Paprasta akcijų rinkos simuliatoriaus programa C++, sukurta su CMake.

## Projekto Struktūra

```
.
├── CMakeLists.txt      # CMake kompiliavimo konfigūracija
├── main.cpp            # Programos pradžios taškas
├── Stock.h / Stock.cpp # Akcijos klasė
├── Player.h / Player.cpp # Žaidėjo klasė
└── Game.h / Game.cpp   # Žaidimo logika
```

## Kaip Paleisti

### CLion:
1. Atidarykite projektą CLion
2. CLion automatiškai atpažins CMakeLists.txt
3. Spauskite žalią trikampį ▶️ arba **Shift+F10**

### Komandine Eilute:
```bash
cd cmake-build-debug
./StockMarketSimulator.exe
```

## Žaidimo Taisyklės

- **Pradinis balansas:** $1000
- **Žaidimo trukmė:** 20 eilių
- **Akcijų kaina:** Kinta atsitiktinai ±10% kas eilę
- **Veiksmai:**
  - `1` - PIRKTI akciją
  - `2` - PARDUOTI akciją
  - `3` - LAUKTI (praleisti eilę)
- **Tikslas:** Uždirbti kuo daugiau pelno
- **Pabaiga:** Po 20 eilių arba bankroto

---

# Detalus Kodo Paaiškinimas

## 📁 main.cpp - PROGRAMA PRASIDEDA ČIA

```cpp
#include "Game.h"
#include <ctime>
#include <cstdlib>
```

**Kas vyksta:**
- `#include "Game.h"` - Įtraukiame Game.h failą, kuriame yra Game klasės aprašymas
- `#include <ctime>` - Biblioteka laikui (time() funkcija)
- `#include <cstdlib>` - Standartinė biblioteka (srand(), rand())

---

```cpp
int main() {
```
**Kas vyksta:** **PROGRAMA PRASIDEDA ČIA!** Kiekviena C++ programa prasideda nuo `main()` funkcijos.

---

```cpp
    srand(static_cast<unsigned int>(time(0)));
```
**Kas vyksta (LABAI SVARBU):**
- `time(0)` - gauna dabartinį laiką sekundėmis (pvz. 1699034567)
- `static_cast<unsigned int>(...)` - paverčia į sveikąjį skaičių
- `srand(...)` - nustato atsitiktinių skaičių generatoriaus "pradžią" (seed)
- **KODĖL?** Kad kiekvieną kartą paleidus programą akcijų kainos keistųsi skirtingai!

---

```cpp
    Game game;
```
**Kas vyksta:**
- Sukuriamas `Game` objektas (kintamasis `game`)
- **AUTOMATIŠKAI iškviečiamas `Game()` konstruktorius!** → Pereina į `Game.cpp:5`
- Konstruktorius inicializuoja žaidimą

---

```cpp
    game.run();
```
**Kas vyksta:**
- Iškviečiama `run()` funkcija ant `game` objekto
- **Čia prasideda visas žaidimas!** → Pereina į `Game.cpp:63`
- Šis metodas vykdomas iki žaidimo pabaigos

---

```cpp
    return 0;
```
**Kas vyksta:**
- Programa baigiasi
- `0` reiškia "viskas OK" (sėkmingai baigėsi)
- Operacinė sistema gauna šį kodą

---

## 📁 Stock.h - AKCIJOS KLASĖS APRAŠYMAS

```cpp
#ifndef STOCK_H
#define STOCK_H
```
**Kas vyksta:** "Include guard" - apsauga nuo dvigubo įtraukimo
- Jei `STOCK_H` dar neaprašytas → apibrėžk jį
- Jei jau aprašytas → praleisk visą failą
- **KODĖL?** Kitaip kompiliatorius gaus klaidą "class Stock defined twice"

---

```cpp
#include <string>
```
**Kas vyksta:** Įtraukiame `string` biblioteką, kad galėtume naudoti `std::string` (tekstą).

---

```cpp
class Stock {
```
**Kas vyksta:** **Pradedame kurti `Stock` klasę** - tai "planas" kaip turėtų atrodyti akcija.

---

```cpp
private:
    std::string name;
    double price;
    double minPrice;
    double maxPrice;
```
**Kas vyksta:**
- `private:` - Visa žemiau šio žodžio yra **PRIVATU** - prieiti gali tik pati klasė
- `name` - akcijos pavadinimas (pvz. "TECH")
- `price` - **DABARTINĖ KAINA** (pvz. 100.50)
- `minPrice` - mažiausia galima kaina (10.0)
- `maxPrice` - didžiausia galima kaina (500.0)

---

```cpp
public:
    Stock(const std::string& stockName, double initialPrice);
```
**Kas vyksta:** **KONSTRUKTORIUS** - specialus metodas, kuris iškviečiamas kuriant objektą
- Parametrai:
  - `stockName` - pavadinimas (pvz. "TECH")
  - `initialPrice` - pradinė kaina (pvz. 100.0)
- **KAI?** Kai parašome `Stock stock("TECH", 100.0);`
- Realizacija yra `Stock.cpp:5`

---

```cpp
    void updatePrice();
```
**Kas vyksta:** Metodas, kuris **PAKEIČIA KAINĄ** atsitiktinai
- `void` - nieko negrąžina
- Realizacija `Stock.cpp:9`

---

```cpp
    double getPrice() const;
    std::string getName() const;
```
**Kas vyksta:**
- `getPrice()` - **GRĄŽINA DABARTINĘ KAINĄ**
- `getName()` - **GRĄŽINA PAVADINIMĄ**
- `const` - pažadas, kad šie metodai NIEKO nekeičia objekte

---

## 📁 Stock.cpp - AKCIJOS KLASĖS REALIZACIJA

```cpp
Stock::Stock(const std::string& stockName, double initialPrice)
    : name(stockName), price(initialPrice), minPrice(10.0), maxPrice(500.0) {
}
```
**Kas vyksta:** **KONSTRUKTORIUS** - čia inicializuojamas Stock objektas
- `Stock::Stock` - tai `Stock` klasės konstruktorius
- **INICIALIZATORIŲ SĄRAŠAS:**
  - `name(stockName)` → `name` gauna reikšmę iš parametro
  - `price(initialPrice)` → `price` gauna pradinę kainą
  - `minPrice(10.0)` → nustatoma minimali kaina 10
  - `maxPrice(500.0)` → nustatoma maksimali kaina 500

**PAVYZDYS:**
```cpp
Stock myStock("TECH", 100.0);
// name = "TECH"
// price = 100.0
// minPrice = 10.0
// maxPrice = 500.0
```

---

```cpp
void Stock::updatePrice() {
    double change = (rand() % 21 - 10) / 100.0;
    price = price * (1.0 + change);

    if (price < minPrice) price = minPrice;
    if (price > maxPrice) price = maxPrice;
}
```
**Kas vyksta (LABAI DETALIAI):**

**Eilutė: `double change = (rand() % 21 - 10) / 100.0;`**

1. `rand()` - atsitiktinis skaičius (pvz. 43829)
2. `% 21` - MODULIS, likutis dalijant iš 21 → gauna skaičių nuo **0 iki 20**
   - Pavyzdys: `43829 % 21 = 7`
3. `- 10` - atimame 10 → gauna skaičių nuo **-10 iki +10**
   - Pavyzdys: `7 - 10 = -3`
4. `/ 100.0` - dalijame iš 100 → gauna **-0.10 iki +0.10** (t.y. -10% iki +10%)
   - Pavyzdys: `-3 / 100.0 = -0.03` (t.y. -3%)

**REZULTATAS:** `change` = pokytis procentais (pvz. -0.03 = -3%)

---

**Eilutė: `price = price * (1.0 + change);`**

Atnaujina kainą:
- Jei `price = 100` ir `change = -0.03`:
  - `price = 100 * (1.0 + (-0.03))`
  - `price = 100 * 0.97`
  - `price = 97` → **Kaina nukrito 3%!**

- Jei `price = 100` ir `change = 0.07`:
  - `price = 100 * (1.0 + 0.07)`
  - `price = 100 * 1.07`
  - `price = 107` → **Kaina pakilo 7%!**

---

**Eilutės: Apsauga nuo ekstremalių kainų**
```cpp
if (price < minPrice) price = minPrice;
if (price > maxPrice) price = maxPrice;
```
- Jei kaina < 10 → nustato į 10
- Jei kaina > 500 → nustato į 500
- **KODĖL?** Kad žaidimas būtų realistiškas

---

```cpp
double Stock::getPrice() const {
    return price;
}

std::string Stock::getName() const {
    return name;
}
```
**Kas vyksta:** **GETTERS** - tiesiog grąžina reikšmes
- `const` - pažadas, kad reikšmės nekeisis

---

## 📁 Player.h - ŽAIDĖJO KLASĖS APRAŠYMAS

```cpp
class Player {
private:
    double balance;
    int stocksOwned;
    const double startingBalance;
```
**Kas vyksta:**
- `balance` - **DABARTINIS PINIGŲ BALANSAS** (pvz. 850.50)
- `stocksOwned` - **KIEK AKCIJŲ TURIME** (0, 1, 2, 3...)
- `startingBalance` - pradinis balansas (1000.0), **NIEKADA NESIKEIČIA!**

---

```cpp
public:
    Player();
    bool buyStock(double price);
    bool sellStock(double price);
    double getBalance() const;
    int getStocksOwned() const;
    double getTotalValue(double currentStockPrice) const;
    double getProfitLoss() const;
    bool isBankrupt() const;
```
**Metodai:**
- `Player()` - konstruktorius
- `buyStock()` - pirkti akciją (grąžina true jei pavyko)
- `sellStock()` - parduoti akciją (grąžina true jei pavyko)
- `getBalance()` - dabartinis balansas
- `getStocksOwned()` - kiek akcijų turime
- `getTotalValue()` - bendra vertė (balansas + akcijų vertė)
- `getProfitLoss()` - pelnas/nuostolis
- `isBankrupt()` - ar bankrutavome

---

## 📁 Player.cpp - ŽAIDĖJO KLASĖS REALIZACIJA

```cpp
Player::Player() : balance(1000.0), stocksOwned(0), startingBalance(1000.0) {
}
```
**Kas vyksta:** **KONSTRUKTORIUS** - sukuria naują žaidėją
- Pradedame su $1000
- Neturime akcijų (0)
- Įsimename pradinį balansą

---

```cpp
bool Player::buyStock(double price) {
    if (balance >= price) {
        balance -= price;
        stocksOwned++;
        return true;
    }
    return false;
}
```
**Kas vyksta:** Metodas **PIRKTI AKCIJĄ**

**Žingsnis po žingsnio:**
1. `if (balance >= price)` - Patikrina ar **PAKANKA PINIGŲ**
   - Pavyzdys: `balance = 150`, `price = 100` → `150 >= 100` = TRUE ✓
2. `balance -= price` - **ATIMAME KAINĄ IŠ BALANSO**
   - `balance = 150 - 100 = 50`
3. `stocksOwned++` - **PADIDINAME AKCIJŲ SKAIČIŲ**
   - `stocksOwned = 2 + 1 = 3`
4. `return true` - **PIRKIMAS SĖKMINGAS!**

**PAVYZDYS:**
```
PRIEŠ: balance=150, stocksOwned=2, price=100
→ 150 >= 100? TRUE
→ balance = 150 - 100 = 50
→ stocksOwned = 2 + 1 = 3
→ return true
PO: balance=50, stocksOwned=3
```

---

```cpp
bool Player::sellStock(double price) {
    if (stocksOwned > 0) {
        balance += price;
        stocksOwned--;
        return true;
    }
    return false;
}
```
**Kas vyksta:** Metodas **PARDUOTI AKCIJĄ**

**Žingsnis po žingsnio:**
1. `if (stocksOwned > 0)` - Patikrina ar **TURIME AKCIJŲ**
2. `balance += price` - **PRIDEDA KAINĄ PRIE BALANSO** (gauname pinigų!)
   - `balance = 50 + 120 = 170`
3. `stocksOwned--` - **SUMAŽINA AKCIJŲ SKAIČIŲ**
   - `stocksOwned = 3 - 1 = 2`
4. `return true` - **PARDAVIMAS SĖKMINGAS!**

**PAVYZDYS:**
```
PRIEŠ: balance=50, stocksOwned=3, price=120
→ 3 > 0? TRUE
→ balance = 50 + 120 = 170
→ stocksOwned = 3 - 1 = 2
→ return true
PO: balance=170, stocksOwned=2
```

---

```cpp
double Player::getTotalValue(double currentStockPrice) const {
    return balance + (stocksOwned * currentStockPrice);
}
```
**Kas vyksta:** Apskaičiuoja **BENDRĄ TURTĄ**

**PAVYZDYS:**
- `balance = 500`
- `stocksOwned = 3`
- `currentStockPrice = 150`
- **REZULTATAS:** `500 + (3 * 150) = 500 + 450 = 950`

---

```cpp
double Player::getProfitLoss() const {
    return balance - startingBalance;
}
```
**Kas vyksta:** Apskaičiuoja **PELNĄ/NUOSTOLĮ**

**PAVYZDYS:**
- `balance = 1200` (dabar)
- `startingBalance = 1000` (pradžioje)
- **REZULTATAS:** `1200 - 1000 = +200` (PELNAS!)

---

```cpp
bool Player::isBankrupt() const {
    return balance <= 0 && stocksOwned == 0;
}
```
**Kas vyksta:** Patikrina ar **BANKRUTAVOME**
- `&&` - IR operatorius (abu turi būti TRUE)
- Bankrotas tik jei `balance <= 0` **IR** `stocksOwned == 0`
- Pavyzdys: `balance=0, stocks=5` → ne bankrotas (turim akcijų!)
- Pavyzdys: `balance=0, stocks=0` → **BANKROTAS!**

---

## 📁 Game.h - ŽAIDIMO KLASĖS APRAŠYMAS

```cpp
class Game {
private:
    Stock stock;
    Player player;
    int maxTurns;
    int currentTurn;

    void displayStatus();
    void displayFinalResults();
    int getPlayerAction();

public:
    Game();
    void run();
};
```
**Kas vyksta:**
- `stock` - akcijos objektas
- `player` - žaidėjo objektas
- `maxTurns` - maksimalus eilių skaičius (20)
- `currentTurn` - dabartinė eilė (1, 2, 3... 20)
- **Privatūs metodai:** `displayStatus()`, `displayFinalResults()`, `getPlayerAction()`
- **Viešas metodas:** `run()` - pagrindinis žaidimo ciklas

---

## 📁 Game.cpp - ŽAIDIMO LOGIKA (SVARBIAUSIAS!)

```cpp
Game::Game() : stock("TECH", 100.0), maxTurns(20), currentTurn(1) {
}
```
**Kas vyksta:** **KONSTRUKTORIUS**
- Sukuria akcijos objektą: `stock("TECH", 100.0)`
  - **ČIA KVIEČIAMAS `Stock::Stock` konstruktorius!** → `Stock.cpp:5`
- Nustato `maxTurns = 20`
- Nustato `currentTurn = 1`
- `player` kviečiamas default konstruktorius → `Player.cpp:3`

---

### displayStatus() - RODO DABARTINĘ INFORMACIJĄ

```cpp
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
```
**Kas vyksta:** Atspausdina dabartinę būseną

**Išvedimo pavyzdys:**
```
========================================
EILE: 5/20
========================================
Akcija: TECH
Kaina: $105.50
----------------------------------------
Jusu balansas: $850.50
Turimos akcijos: 3
Bendra verte: $1167.00
========================================
```

**Detaliai:**
- `std::cout` - išveda tekstą į konsolę
- `<<` - operatorius "srauto" perdavimui
- `\n` - nauja eilutė
- `std::fixed` - rodyti skaičių su fiksuotu kablelio vieta
- `std::setprecision(2)` - 2 skaičiai po kablelio
- `stock.getName()` - **KVIEČIA** `Stock::getName()` → grąžina "TECH"
- `stock.getPrice()` - **KVIEČIA** `Stock::getPrice()` → grąžina kainą
- `player.getBalance()` - **KVIEČIA** `Player::getBalance()` → grąžina balansą
- `player.getTotalValue(price)` - **KVIEČIA** `Player::getTotalValue()` → apskaičiuoja bendrą vertę

---

### displayFinalResults() - RODO FINALIUS REZULTATUS

```cpp
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
```
**Kas vyksta:** Rodo galutinį rezultatą

**Pelno skaičiavimas:**
```cpp
double profitLoss = player.getTotalValue(stock.getPrice()) - 1000.0;
```
- Bendra vertė dabar - pradinis balansas (1000)
- Pavyzdys: `1200 - 1000 = +200` (PELNAS!)

**Sąlygos:**
- `if (profitLoss > 0)` → PELNAS
- `else if (profitLoss < 0)` → NUOSTOLIS
- `else` → Nei pelno, nei nuostolio

---

### getPlayerAction() - GAUNA ŽAIDĖJO PASIRINKIMĄ

```cpp
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
```
**Kas vyksta:** Gauna įvedimą iš vartotojo

**Žingsnis po žingsnio:**
1. Išveda meniu
2. `std::cin >> action;` - **LAUKIA ĮVEDIMO!** Programa sustoja ir laukia
3. `while (action < 1 || action > 3)` - Validacija
   - Jei įvedė ne 1, 2 arba 3 → prašo įvesti iš naujo
   - `||` - ARBA operatorius
4. `return action;` - Grąžina pasirinkimą (1, 2 arba 3)

---

### run() - PAGRINDINIS ŽAIDIMO CIKLAS

```cpp
void Game::run() {
    std::cout << "========================================\n";
    std::cout << "  AKCIJU RINKOS SIMULIATORIUS\n";
    std::cout << "========================================\n";
    std::cout << "Pradinis balansas: $1000\n";
    std::cout << "Eilu skaicius: " << maxTurns << "\n";
    std::cout << "Tikslas: Uzdirbti kuo daugiau pinigu!\n";
    std::cout << "========================================\n";
```
**Kas vyksta:** Išveda intro tekstą

---

```cpp
    while (currentTurn <= maxTurns && !player.isBankrupt()) {
```
**Kas vyksta:** **PAGRINDINIS CIKLAS** - kartoja kol:
- `currentTurn <= maxTurns` - dar nepasibaigė eilės (1-20)
- **IR** (`&&`)
- `!player.isBankrupt()` - dar nebankrutavome
  - `!` - NE operatorius (neigimas)

**PAVYZDYS:**
- Eilė 5, ne bankrotas → `5 <= 20` IR `!false` = `true` IR `true` = **TRUE** → tęsia
- Eilė 21 → `21 <= 20` = **FALSE** → sustoja
- Bankrotas → `!true` = **FALSE** → sustoja

---

```cpp
        displayStatus();
```
**Kas vyksta:** **KVIEČIA** `displayStatus()` → Rodo dabartinę informaciją

---

```cpp
        int action = getPlayerAction();
```
**Kas vyksta:** **KVIEČIA** `getPlayerAction()`
- **PROGRAMA SUSTOJA IR LAUKIA ĮVEDIMO!**
- Vartotojas įveda 1, 2 arba 3
- Reikšmė įrašoma į `action`

---

```cpp
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
```
**Kas vyksta (LABAI DETALIAI):**

**Jei `action == 1` (žaidėjas pasirinko PIRKTI):**

1. `stock.getPrice()` - gauna dabartinę kainą (pvz. 105.50) → `Stock.cpp:19`
2. `player.buyStock(105.50)` - **KVIEČIA** `Player::buyStock()` → `Player.cpp:6`

**ĮEINA Į `Player.cpp:6`:**
- Patikrina ar `balance >= 105.50`
- Jei TAIP → atima iš balanso, padidina `stocksOwned`, grąžina `true`
- Jei NE → grąžina `false`

**GRĮŽTA ATGAL:**
3. `if (true)` → išveda "Nusipirkote..."
4. `if (false)` → išveda "Nepakanka pinigu..."

5. `break;` - išeina iš `switch` bloko

---

```cpp
            case 2: // PARDUOTI
                if (player.sellStock(stock.getPrice())) {
                    std::cout << "\n>>> Pardavete 1 akcija uz $"
                              << std::fixed << std::setprecision(2)
                              << stock.getPrice() << "\n";
                } else {
                    std::cout << "\n>>> Neturite akciju pardavimui!\n";
                }
                break;
```
**Kas vyksta:** **Jei `action == 2`** (žaidėjas pasirinko PARDUOTI)
- `player.sellStock(price)` - **KVIEČIA** `Player::sellStock()` → `Player.cpp:15`
- Grąžina `true` jei pavyko, `false` jei neturi akcijų

---

```cpp
            case 3: // LAUKTI
                std::cout << "\n>>> Praleidziate eile...\n";
                break;
```
**Kas vyksta:** **Jei `action == 3`** → Nieko nedaro, tik pranešimas

---

```cpp
        stock.updatePrice();
```
**Kas vyksta (LABAI SVARBU!):**
- **KVIEČIA** `Stock::updatePrice()` → `Stock.cpp:9`
- **ČIA KAINA PASIKEIČIA!**
- `rand() % 21 - 10` → gauna -10 iki +10
- Kaina pasikeičia ±10%
- **PAVYZDYS:** Kaina 100 → gali tapti 90-110

---

```cpp
        currentTurn++;
```
**Kas vyksta:** Padidina eilės numerį
- `currentTurn = currentTurn + 1`
- Pavyzdys: buvome eilėje 5 → dabar 6

---

```cpp
    } // GRĮŽTA ATGAL Į while (currentTurn <= maxTurns...)
```
**Kas vyksta:** **GRĮŽTA ATGAL Į CIKLO PRADŽIĄ!**
- Patikrina sąlygą
- Jei TRUE → kartoja viską iš naujo
- Jei FALSE → išeina iš ciklo

---

```cpp
    if (player.isBankrupt()) {
        std::cout << "\n\n!!! BANKROTAS !!! Praradote visus pinigus ir akcijas!\n";
    }

    displayFinalResults();
}
```
**Kas vyksta:**
- Patikrina ar bankrutavome
- **KVIEČIA** `displayFinalResults()` → Rodo galutinį rezultatą
- **`run()` FUNKCIJA BAIGIASI!** → Grįžta į `main.cpp:11`

---

## 📁 CMakeLists.txt - KOMPILIAVIMO INSTRUKCIJOS

```cmake
cmake_minimum_required(VERSION 3.30)
```
**Kas vyksta:** Nurodo minimalią CMake versiją

---

```cmake
project(StockMarketSimulator)
```
**Kas vyksta:** Projekto pavadinimas

---

```cmake
set(CMAKE_CXX_STANDARD 11)
```
**Kas vyksta:** Nustato C++ standartą į C++11

---

```cmake
add_executable(StockMarketSimulator
    main.cpp
    Stock.cpp
    Player.cpp
    Game.cpp
)
```
**Kas vyksta:** Sukuria vykdomąjį failą
- Pavadinimas: `StockMarketSimulator.exe` (Windows)
- Sukompiluoja visus .cpp failus
- **KODĖL NĖRA .h FAILŲ?** Nes .h failai įtraukiami per `#include`, ne kompiliuojami

**KOMPILIAVIMO PROCESAS:**
1. `main.cpp` → `main.o` (objektinis failas)
2. `Stock.cpp` → `Stock.o`
3. `Player.cpp` → `Player.o`
4. `Game.cpp` → `Game.o`
5. Linker sujungia visus .o failus → `StockMarketSimulator.exe`

---

# 🔄 VISOS PROGRAMOS VYKDYMO EIGA

## 1. PROGRAMA PRASIDEDA

```
main.cpp:5 → int main()
main.cpp:7 → srand(time(0))  [Inicializuoja atsitiktinius skaičius]
```

---

## 2. SUKURIAMAS ŽAIDIMAS

```
main.cpp:10 → Game game;
  ↓
Game.cpp:5 → Game::Game() konstruktorius
  ↓
  stock("TECH", 100.0) → Stock::Stock konstruktorius
    ↓
    Stock.cpp:5-6 → name="TECH", price=100.0, minPrice=10, maxPrice=500
  ↓
  player → Player::Player() konstruktorius
    ↓
    Player.cpp:3 → balance=1000, stocksOwned=0, startingBalance=1000
  ↓
  maxTurns=20, currentTurn=1
```

---

## 3. PALEIDŽIAMAS ŽAIDIMAS

```
main.cpp:11 → game.run();
  ↓
Game.cpp:63 → void Game::run()
Game.cpp:64-70 → Išveda intro tekstą
```

---

## 4. PAGRINDINIS CIKLAS (kartojasi 20 kartų arba iki bankroto)

```
Game.cpp:72 → while(currentTurn <= maxTurns && !player.isBankrupt())
  ↓
Game.cpp:73 → displayStatus()
  ↓ [Rodo dabartinę informaciją]
  Stock.cpp:23 → getName() [Gauna "TECH"]
  Stock.cpp:19 → getPrice() [Gauna dabartinę kainą]
  Player.cpp:24 → getBalance() [Gauna balansą]
  Player.cpp:28 → getStocksOwned() [Gauna akcijų skaičių]
  Player.cpp:32 → getTotalValue() [Apskaičiuoja bendrą vertę]
  ↓
Game.cpp:75 → action = getPlayerAction()
  ↓ [LAUKIA VARTOTOJO ĮVEDIMO - 1, 2 arba 3]
  Game.cpp:53 → std::cin >> action
  ↓
Game.cpp:77 → switch(action)

  JEIGU PASIRINKO 1 (PIRKTI):
    Game.cpp:79 → player.buyStock(stock.getPrice())
      ↓
      Stock.cpp:19 → getPrice() [Gauna kainą, pvz. 105.50]
      ↓
      Player.cpp:6 → bool Player::buyStock(105.50)
        Player.cpp:7 → Patikrina: balance >= price?
        Player.cpp:8 → balance -= price [Atima pinigus]
        Player.cpp:9 → stocksOwned++ [Prideda akciją]
        Player.cpp:10 → return true
      ↓
    Game.cpp:80-82 → Išveda "Nusipirkote..."

  JEIGU PASIRINKO 2 (PARDUOTI):
    Game.cpp:89 → player.sellStock(stock.getPrice())
      ↓
      Player.cpp:15 → bool Player::sellStock(price)
        Player.cpp:16 → Patikrina: stocksOwned > 0?
        Player.cpp:17 → balance += price [Gauna pinigų]
        Player.cpp:18 → stocksOwned-- [Atima akciją]
        Player.cpp:19 → return true
      ↓
    Game.cpp:90-92 → Išveda "Pardavete..."

  JEIGU PASIRINKO 3 (LAUKTI):
    Game.cpp:99 → Išveda "Praleidziate eile..."

  ↓
Game.cpp:104 → stock.updatePrice()
  ↓
  Stock.cpp:9 → void Stock::updatePrice()
    Stock.cpp:11 → change = (rand() % 21 - 10) / 100.0
                   [Gauna -0.10 iki +0.10]
    Stock.cpp:12 → price = price * (1.0 + change)
                   [Kaina pasikeičia ±10%]
    Stock.cpp:15-16 → Patikrina ribas (10-500)
  ↓
Game.cpp:105 → currentTurn++
  ↓
  GRĮŽTA Į Game.cpp:72 (ciklo pradžią)
```

---

## 5. CIKLAS BAIGIASI

```
Game.cpp:72 → Sąlyga FALSE (21 eilė arba bankrotas)
  ↓
Game.cpp:108 → Patikrina ar bankrotas
  ↓
Game.cpp:112 → displayFinalResults()
  ↓
  Game.cpp:30 → profitLoss = getTotalValue() - 1000
  Game.cpp:33-41 → Rodo pelną/nuostolį
```

---

## 6. PROGRAMA BAIGIASI

```
Game.cpp:113 → } [run() baigiasi]
  ↓
main.cpp:11 → game.run() [grįžta]
  ↓
main.cpp:13 → return 0
  ↓
PROGRAMA UŽSIDARO
```

---

# 📊 DUOMENŲ SRAUTAI - PAVYZDYS

## PIRKIMO VEIKSMAS

```
PRIEŠ:
  player.balance = 1000.0
  player.stocksOwned = 0
  stock.price = 100.0

VARTOTOJAS ĮVEDA: 1 (PIRKTI)

SRAUTAS:
  1. Game.cpp:79 → player.buyStock(100.0)
  2. Player.cpp:7 → 1000.0 >= 100.0? TRUE ✓
  3. Player.cpp:8 → balance = 1000.0 - 100.0 = 900.0
  4. Player.cpp:9 → stocksOwned = 0 + 1 = 1
  5. Player.cpp:10 → return true
  6. Game.cpp:79 → if(true) → TRUE
  7. Game.cpp:80 → Išveda "Nusipirkote..."

PO TO:
  player.balance = 900.0
  player.stocksOwned = 1
  stock.price = 100.0 (dar nesikeičia)

TADA:
  Game.cpp:104 → stock.updatePrice()
    - rand() = 43829 (pavyzdys)
    - 43829 % 21 = 7
    - 7 - 10 = -3
    - -3 / 100.0 = -0.03
    - price = 100.0 * (1.0 + (-0.03)) = 100.0 * 0.97 = 97.0

GALUTINIS REZULTATAS:
  player.balance = 900.0
  player.stocksOwned = 1
  stock.price = 97.0 (NUKRITO!)
```

---

# Objektinis Programavimas

Ši programa naudoja **objektinį programavimą (OOP)**:

## 1. Klasės (Classes)
- **Stock** - Atstovauja akcijos objektą
- **Player** - Atstovauja žaidėjo objektą
- **Game** - Valdo žaidimo logiką

## 2. Enkapsuliacija (Encapsulation)
- **Private** kintamieji (`balance`, `price`) - Apsaugoti nuo tiesioginės prieigos
- **Public** metodai (`getPrice()`, `buyStock()`) - Kontroliuota prieiga per metodus

## 3. Atsakomybių Paskirstymas
- **Stock** klasė - Atsakinga už akcijos kainą ir jos pasikeitimus
- **Player** klasė - Atsakinga už balansą ir akcijų valdymą
- **Game** klasė - Atsakinga už žaidimo tėkmę ir vartotojo sąsają

## 4. Konstruktoriai
- Inicializuoja objektus su pradinėmis reikšmėmis
- `Stock::Stock()`, `Player::Player()`, `Game::Game()`

## 5. Metodai
- Funkcijos, kurios veikia su objekto duomenimis
- `updatePrice()` - keičia kainą
- `buyStock()` - perka akciją
- `sellStock()` - parduoda akciją

---

# GitHub Repository

Kodas įkeltas į: https://github.com/DomantasCode/Birza

---

# Autorius

Sukurta su C++ ir CMake.

🤖 Pagelbėjo: Claude Code (Anthropic)
