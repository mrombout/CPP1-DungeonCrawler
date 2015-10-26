#ifndef DUNGEONCRAWLER_STATSCOMMAND_H
#define DUNGEONCRAWLER_STATSCOMMAND_H

#include "command.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace game {
        class StatsCommand : public dc::engine::Command {
        public:
            StatsCommand(dc::model::Player &player);
            virtual void execute() const override;

            static StatsCommand *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
        };
    }
}

#endif //DUNGEONCRAWLER_STATSCOMMAND_H
