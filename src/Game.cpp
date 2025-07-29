#include "Game.h"
#include <iostream>
#include "MenuState.h"

Game& Game::getInstance() {
    static Game instance;
    return instance;
}

bool Game::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!window) {
        std::cerr << "Window Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    running = true;
    changeState(new MenuState());
    return true;
}

void Game::run() {
    SDL_Event event;

   while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (currentState) {
                currentState->handleEvents(event);
            }
        }

        if (currentState) {
            currentState->update();
            currentState->render(renderer);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    if (currentState) {
        delete currentState;
        currentState = nullptr;
    }

}

void Game::changeState(GameState* newState) {
    if (currentState) {
        delete currentState;
    }
    currentState = newState;
}
