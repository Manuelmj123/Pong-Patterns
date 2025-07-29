#ifndef COMMAND_H
#define COMMAND_H

class Paddle;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Paddle& paddle) = 0;
};

#endif
