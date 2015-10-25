#ifndef DUNGEONCRAWLER_REFLECTCOMMAND_H
#define DUNGEONCRAWLER_REFLECTCOMMAND_H

#include "command.h"

namespace dc {
    namespace model {
        class Player;
    }
}

class StatsCommand : public dc::engine::Command {
public:
    StatsCommand(dc::model::Player &player);
    virtual void execute() const override;

private:
    dc::model::Player &mPlayer;
};

#endif //DUNGEONCRAWLER_REFLECTCOMMAND_H
