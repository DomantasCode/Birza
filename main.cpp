#include "Game.h"
#include <ctime>
#include <cstdlib>

int main() {
    // Inicializuojame atsitiktinių skaičių generatorių
    srand(static_cast<unsigned int>(time(0)));

    // Sukuriame ir paleidžiame žaidimą
    Game game;
    game.run();

    return 0;
}