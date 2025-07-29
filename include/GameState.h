#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL.h>

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleEvents(SDL_Event& event) = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif
