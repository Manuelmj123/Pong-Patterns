#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include "Paddle.h"
#include "InputHandler.h"
#include "ScoreManager.h"
#include "HUD.h"
#include "Ball.h"
#include "Brick.h"

#include <vector>
#include <memory>

class PlayState : public GameState {
public:
    PlayState();

    void handleEvents(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

private:
    std::vector<std::shared_ptr<GameObject>> objects;
    std::vector<std::shared_ptr<Brick>> bricks;

    Paddle* paddleRaw = nullptr;
    InputHandler inputHandler;
    ScoreManager scoreManager;
    HUD hud;
    int score = 0;
};

#endif
