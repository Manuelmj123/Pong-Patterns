#include "Game.h"

int main(int argc, char* argv[]) {
    Game& game = Game::getInstance();

    if (!game.init("Pong with Patterns", 800, 600)) {
        return -1;
    }

    game.run();
    game.clean();

    return 0;
}
