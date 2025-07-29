#include "HUD.h"
#include <string>
#include <SDL.h>

void HUD::render(SDL_Renderer* renderer) {
    // We'll improve this later with font. For now: just a white line at the top
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 0, 25, 800, 25);
}
