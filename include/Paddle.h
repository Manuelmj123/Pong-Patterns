#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"
#include <SDL.h>

class Paddle : public GameObject {
public:
    Paddle(int x, int y, int w, int h);

    void update() override;
    void render(SDL_Renderer* renderer) override;

    void moveLeft();
    void moveRight();

    SDL_Rect getRect() const { return rect; } // ✅ Add this line

private:
    SDL_Rect rect;
    int speed;
};

#endif
