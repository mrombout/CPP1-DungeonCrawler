#ifndef DUNGEONCRAWLER_NEWGAMECOMMAND_H
#define DUNGEONCRAWLER_NEWGAMECOMMAND_H

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
            NewGameCommand(dc::game::GameLoop &gameLoop);

            virtual void execute() const override;

        private:
            dc::game::GameLoop &mGameLoop;
        };
    }
}

#endif //DUNGEONCRAWLER_NEWGAMECOMMAND_H
