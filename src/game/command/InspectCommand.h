#ifndef DUNGEONCRAWLER_INSPECTCOMMAND_H
#define DUNGEONCRAWLER_INSPECTCOMMAND_H

#include "command.h"

class InspectCommand : public dc::engine::Command {
public:
    virtual void execute(dc::engine::CommandParameters &parameters) const override;
};

#endif //DUNGEONCRAWLER_INSPECTCOMMAND_H
