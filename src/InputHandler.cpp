#include "InputHandler.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"

std::shared_ptr<Command> InputHandler::handleInput(const Uint8* keystates) {
    if (keystates[SDL_SCANCODE_LEFT]) {
        return std::make_shared<MoveLeftCommand>();
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        return std::make_shared<MoveRightCommand>();
    }
    return nullptr;
}
