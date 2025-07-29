#include "Brick.h"

Brick::Brick(int x, int y, int w, int h) {
    rect = {x, y, w, h};
}

void Brick::render(SDL_Renderer* renderer) {
    if (isDestroyed) return;
    SDL_SetRenderDrawColor(renderer, 200, 200, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
