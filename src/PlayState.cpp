#include "PlayState.h"
#include "Game.h"
#include "GameObjectFactory.h"
#include "GameOverState.h"

#include <SDL.h>

PlayState::PlayState() {
    // Create and store paddle
    auto paddleObj = GameObjectFactory::create("Paddle");
    paddleRaw = dynamic_cast<Paddle*>(paddleObj.get());
    objects.push_back(paddleObj);

    // Create and store ball
    auto ballObj = GameObjectFactory::create("Ball");
    auto ball = std::dynamic_pointer_cast<Ball>(ballObj);
    ball->setPaddle(paddleRaw);
    objects.push_back(ballObj);

    // Create and store bricks
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 8; ++col) {
            auto brick = std::make_shared<Brick>(col * 90 + 10, row * 30 + 30, 80, 20);
            bricks.push_back(brick);
            objects.push_back(brick);
        }
    }

    // Set up score observer
    scoreManager.addObserver(&hud);
}

void PlayState::handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        SDL_Event quit;
        quit.type = SDL_QUIT;
        SDL_PushEvent(&quit);
    }

    const Uint8* keystates = SDL_GetKeyboardState(nullptr);
    std::shared_ptr<Command> command = inputHandler.handleInput(keystates);

    if (command && paddleRaw) {
        command->execute(*paddleRaw);
    }
}

void PlayState::update() {
    for (auto& obj : objects) {
        obj->update();
    }

    auto ball = std::dynamic_pointer_cast<Ball>(objects[1]);

    for (auto& brick : bricks) {
        if (!brick->isDestroyed) {
            SDL_Rect brickRect = brick->getRect();
            SDL_Rect ballRect = ball->getRect();

            if (SDL_HasIntersection(&brickRect, &ballRect)) {
                brick->isDestroyed = true;
                ball->reverseY();
                score += 100;
                scoreManager.notify(score);
            }
        }
    }

    if (ball->isOutOfBounds()) {
        Game::getInstance().changeState(new GameOverState());
    }
}

void PlayState::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
    SDL_RenderClear(renderer);

    for (auto& obj : objects) {
        obj->render(renderer);
    }

    hud.render(renderer);
}
