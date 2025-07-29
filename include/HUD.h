#ifndef HUD_H
#define HUD_H

#include "Observer.h"
#include <SDL.h>

class HUD : public Observer {
public:
    void onNotify(int score) override {
        this->score = score;
    }

    void render(SDL_Renderer* renderer);

private:
    int score = 0;
};

#endif
