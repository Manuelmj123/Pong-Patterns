#ifndef MOVELEFTCOMMAND_H
#define MOVELEFTCOMMAND_H

#include "Command.h"
#include "Paddle.h"

class MoveLeftCommand : public Command {
public:
    void execute(Paddle& paddle) override {
        paddle.moveLeft();
    }
};

#endif
