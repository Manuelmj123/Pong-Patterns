#ifndef BRICK_H
#define BRICK_H

#include "GameObject.h"
#include <SDL.h>

class Brick : public GameObject {
public:
    Brick(int x, int y, int w, int h);

    void update() override {}
    void render(SDL_Renderer* renderer) override;
    SDL_Rect getRect() const { return rect; }
    bool isDestroyed = false;

private:
    SDL_Rect rect;
};

#endif
