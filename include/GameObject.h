#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif
