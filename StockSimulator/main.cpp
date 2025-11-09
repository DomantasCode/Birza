#include "Game.h"
#include <windows.h>

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Game game(1000.0, 100.0, 10);

    game.start();

    return 0;
}