#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>
#include <memory>
#include "Command.h"

class InputHandler {
public:
    std::shared_ptr<Command> handleInput(const Uint8* keystates);
};

#endif
