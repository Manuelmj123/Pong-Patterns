#ifndef MOVERIGHTCOMMAND_H
#define MOVERIGHTCOMMAND_H

#include "Command.h"
#include "Paddle.h"

class MoveRightCommand : public Command {
public:
    void execute(Paddle& paddle) override {
        paddle.moveRight();
    }
};

#endif
