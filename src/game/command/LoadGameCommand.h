#ifndef DUNGEONCRAWLER_LOADGAMECOMMAND_H
#define DUNGEONCRAWLER_LOADGAMECOMMAND_H

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
            LoadGameCommand(dc::game::GameLoop &gameLoop, dc::game::ItemLoader &itemLoader);

            virtual void execute() const override;

            static LoadGameCommand *create();

        private:
            dc::game::GameLoop &mGameLoop;
            dc::game::ItemLoader &mItemLoader;
        };
    }
}

#endif //DUNGEONCRAWLER_LOADGAMECOMMAND_H
