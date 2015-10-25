#ifndef DUNGEONCRAWLER_FLEECOMMAND_H
#define DUNGEONCRAWLER_FLEECOMMAND_H

#include "command.h"

class FleeCommand : public dc::engine::Command {
public:
    virtual void execute() const override;
};

#endif //DUNGEONCRAWLER_FLEECOMMAND_H
