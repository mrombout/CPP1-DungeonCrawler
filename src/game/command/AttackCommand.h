#ifndef DUNGEONCRAWLER_ATTACKCOMMAND_H
#define DUNGEONCRAWLER_ATTACKCOMMAND_H

#include "command.h"

namespace dc {
    namespace model {
        class Mob;
        class Player;
    }
}

class AttackCommand : public dc::engine::Command {
public:
    AttackCommand(dc::model::Player &player);

    virtual void execute() const override;

    static AttackCommand *create(Parameters parameters);

private:
    dc::model::Player &mPlayer;
};

#endif //DUNGEONCRAWLER_ATTACKCOMMAND_H
