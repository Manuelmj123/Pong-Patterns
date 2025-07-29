#include "GameOverState.h"
#include <SDL.h>

void GameOverState::handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        SDL_Event quit;
        quit.type = SDL_QUIT;
        SDL_PushEvent(&quit);
    }
}

void GameOverState::update() {}

void GameOverState::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
    SDL_RenderClear(renderer);
    // Future: add "Game Over" text here
}
