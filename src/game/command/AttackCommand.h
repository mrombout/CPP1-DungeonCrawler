#ifndef DUNGEONCRAWLER_ATTACKCOMMAND_H
#define DUNGEONCRAWLER_ATTACKCOMMAND_H

#include <Player.h>
#include "command.h"

namespace dc {
    namespace model {
        class Mob;
    }
}

class AttackCommand : public dc::engine::Command {
public:
    AttackCommand(dc::model::Player &player);

    virtual void execute() const override;

private:
    dc::model::Player &mPlayer;
};

#endif //DUNGEONCRAWLER_ATTACKCOMMAND_H
