#ifndef DUNGEONCRAWLER_LOADGAMECOMMAND_H
#define DUNGEONCRAWLER_LOADGAMECOMMAND_H

#include <generator/MobGenerator.h>
#include "loader/TrapLoader.h"
#include "loader/MobLoader.h"
#include "Inventory.h"
#include "loader/ItemLoader.h"
#include "command.h"

namespace dc {
    namespace game {
        class GameLoop;
    }
}

namespace dc {
    namespace game {
        class LoadGameCommand : public game::Command {
        public:
            LoadGameCommand(dc::game::GameLoop &gameLoop, dc::game::ItemLoader &itemLoader, dc::game::TrapLoader &trapLoader, dc::game::MobGenerator &mobGenerator);

            virtual void execute() const override;

            static LoadGameCommand *create();

        private:
            dc::game::GameLoop &mGameLoop;
            dc::game::ItemLoader &mItemLoader;
            dc::game::TrapLoader &mTrapLoader;
            dc::game::MobGenerator &mMobGenerator;
        };
    }
}

#endif //DUNGEONCRAWLER_LOADGAMECOMMAND_H
