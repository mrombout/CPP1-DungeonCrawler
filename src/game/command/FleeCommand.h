#ifndef DUNGEONCRAWLER_FLEECOMMAND_H
#define DUNGEONCRAWLER_FLEECOMMAND_H

#include "command.h"

class FleeCommand : public dc::engine::Command {
    virtual void execute(dc::engine::CommandParameters &parameters) const override;
};

#endif //DUNGEONCRAWLER_FLEECOMMAND_H
