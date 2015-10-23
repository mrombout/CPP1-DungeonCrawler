#ifndef DUNGEONCRAWLER_ATTACKCOMMAND_H
#define DUNGEONCRAWLER_ATTACKCOMMAND_H

#include "command.h"

namespace dc {
    namespace model {
        class Mob;
    }
}

class AttackCommand : public dc::engine::Command {
public:
    AttackCommand(dc::model::Mob &mob);

    virtual void execute(dc::engine::CommandParameters &parameters) const override;

private:
    dc::model::Mob &mMob;
};

#endif //DUNGEONCRAWLER_ATTACKCOMMAND_H
