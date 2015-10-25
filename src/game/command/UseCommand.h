#ifndef DUNGEONCRAWLER_USECOMMAND_H
#define DUNGEONCRAWLER_USECOMMAND_H

#include <string>
#include "command.h"

class UseCommand : public dc::engine::Command {
public:
    UseCommand(std::string item);

    virtual void execute(dc::engine::CommandParameters &parameters) const override;

private:
    std::string mItemName;
};

#endif //DUNGEONCRAWLER_USECOMMAND_H
