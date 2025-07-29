#include "Paddle.h"
#include <SDL.h>

Paddle::Paddle(int x, int y, int w, int h)
    : speed(50) {
    rect = {x, y, w, h};
}

void Paddle::moveLeft() {
    rect.x -= speed;
}

void Paddle::moveRight() {
    rect.x += speed;
}

void Paddle::update() {
    // Movement will be handled by Command pattern
}

void Paddle::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}
