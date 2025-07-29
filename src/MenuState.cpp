#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"
#include <iostream>

void MenuState::handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        Game::getInstance().changeState(new PlayState());
    }
}

void MenuState::update() {
    // Nothing for now
}

void MenuState::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);
    SDL_RenderClear(renderer);
    // Optional: render text here later
}
