#ifndef DUNGEONCRAWLER_NEWGAMECOMMAND_H
#define DUNGEONCRAWLER_NEWGAMECOMMAND_H

#include "loader/ItemLoader.h"
#include "command.h"

namespace dc {
    namespace game {
        class GameLoop;
    }
}

namespace dc {
    namespace game {
        class NewGameCommand : public game::Command {
        public:
            NewGameCommand(dc::game::GameLoop &gameLoop, dc::game::ItemLoader &itemLoader);

            virtual void execute() const override;
            virtual bool isAction() const;

        private:
            dc::game::GameLoop &mGameLoop;
            dc::game::ItemLoader &mItemLoader;
        };
    }
}

#endif //DUNGEONCRAWLER_NEWGAMECOMMAND_H
