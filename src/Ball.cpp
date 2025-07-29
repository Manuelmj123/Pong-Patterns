#include "Ball.h"
#include "Paddle.h"
#include <SDL.h>

Ball::Ball(int x, int y, int size)
    : dx(5), dy(-5), paddle(nullptr) {
    rect = {x, y, size, size};
}

void Ball::update() {
    rect.x += dx;
    rect.y += dy;

    if (rect.x < 0 || rect.x + rect.w > 800) dx *= -1;
    if (rect.y < 0) dy *= -1;

    // Collision with paddle
    if (paddle) {
        SDL_Rect paddleRect = paddle->getRect();
        if (SDL_HasIntersection(&rect, &paddleRect)) {
            dy *= -1;
            rect.y = paddleRect.y - rect.h; // Prevent sticking
        }
    }
}

void Ball::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Ball::setPaddle(Paddle* p) {
    paddle = p;
}

bool Ball::isOutOfBounds() const {
    return rect.y > 600;
}
