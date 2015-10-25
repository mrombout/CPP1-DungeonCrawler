#ifndef DUNGEONCRAWLER_FLEECOMMAND_H
#define DUNGEONCRAWLER_FLEECOMMAND_H

#include "command.h"
#include "GoToCommand.h"

class FleeCommand : public dc::engine::Command {
public:
    FleeCommand(dc::engine::GameLoop &gameLoop, dc::game::GoToCommand *command);
    ~FleeCommand();

    virtual void execute() const override;

    static FleeCommand *create(Parameters parameters);

private:
    dc::engine::GameLoop &mGameLoop;
    dc::game::GoToCommand *mGoToCommand;
};

#endif //DUNGEONCRAWLER_FLEECOMMAND_H
