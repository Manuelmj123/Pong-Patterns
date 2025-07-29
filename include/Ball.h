#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include "GameObject.h"

class Paddle; // Forward declaration

class Ball : public GameObject {
public:
    Ball(int x, int y, int size);

    void update() override;
    void render(SDL_Renderer* renderer) override;

    SDL_Rect getRect() const { return rect; }
    void reverseY() { dy *= -1; }
    void setPaddle(Paddle* p);
    bool isOutOfBounds() const;

private:
    SDL_Rect rect;
    int dx, dy;
    Paddle* paddle = nullptr; // ✅ move this here, not in Ball.cpp
};

#endif
