#ifndef DUNGEONCRAWLER_REFLECTCOMMAND_H
#define DUNGEONCRAWLER_REFLECTCOMMAND_H

#include "command.h"

class StatsCommand : public dc::engine::Command {
public:
    virtual void execute(dc::engine::CommandParameters &parameters) const override;
};

#endif //DUNGEONCRAWLER_REFLECTCOMMAND_H
