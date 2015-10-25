#ifndef DUNGEONCRAWLER_INSPECTCOMMAND_H
#define DUNGEONCRAWLER_INSPECTCOMMAND_H

#include <Game.h>
#include "command.h"

class InspectCommand : public dc::engine::Command {
public:
    InspectCommand(dc::model::Game &game);
    virtual void execute() const override;

    static InspectCommand *create(Parameters parameters);

private:
    dc::model::Game &mGame;
};

#endif //DUNGEONCRAWLER_INSPECTCOMMAND_H
