#ifndef DUNGEONCRAWLER_USECOMMAND_H
#define DUNGEONCRAWLER_USECOMMAND_H

#include <string>
#include "command.h"

namespace dc {
    namespace model {
        class Player;
    }
}

class UseCommand : public dc::engine::Command {
public:
    UseCommand(dc::model::Player &player);
    virtual void execute() const override;

private:
    dc::model::Player &mPlayer;
};

#endif //DUNGEONCRAWLER_USECOMMAND_H
