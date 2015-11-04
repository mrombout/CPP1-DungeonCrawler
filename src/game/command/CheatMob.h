#ifndef DUNGEONCRAWLER_CHEATMOB_H
#define DUNGEONCRAWLER_CHEATMOB_H

#include <generator/MobGenerator.h>
#include "command.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace game {
        class CheatMob : public Command {
        public:
            CheatMob(dc::model::Player &player, dc::game::MobGenerator &mobGenerator);

            virtual void execute() const;
            virtual bool isAction() const;

            static CheatMob *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
            dc::game::MobGenerator &mMobGenerator;
        };
    }
}

#endif //DUNGEONCRAWLER_CHEATMOB_H
