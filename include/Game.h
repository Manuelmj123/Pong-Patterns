#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "GameState.h"

class Game {
public:
    static Game& getInstance();

    bool init(const char* title, int width, int height);
    void run();
    void clean();
    void changeState(GameState* newState);
    bool isRunning() const { return running; }

private:
    Game() = default;
    ~Game() = default;
    GameState* currentState = nullptr;

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    bool running = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

#endif
