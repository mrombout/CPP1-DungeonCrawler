#ifndef DUNGEONCRAWLER_ATTACKCOMMAND_H
#define DUNGEONCRAWLER_ATTACKCOMMAND_H

#include <Mob.h>
#include "command.h"

namespace dc {
    namespace model {
        class Mob;
        class Player;
    }
}

class AttackCommand : public dc::engine::Command {
public:
    AttackCommand(dc::model::Player &player, dc::model::Mob &mob);

    virtual void execute() const override;

    static AttackCommand *create(Parameters parameters);

private:
    dc::model::Player &mPlayer;
    dc::model::Mob &mMob;
};

#endif //DUNGEONCRAWLER_ATTACKCOMMAND_H
