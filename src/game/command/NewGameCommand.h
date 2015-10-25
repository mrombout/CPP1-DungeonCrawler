#ifndef DUNGEONCRAWLER_NEWGAMECOMMAND_H
#define DUNGEONCRAWLER_NEWGAMECOMMAND_H

#include "command.h"

namespace dc {
    namespace engine {
        class GameLoop;
    }
}

namespace dc {
    namespace game {
        class NewGameCommand : public engine::Command {
        public:
            NewGameCommand(dc::engine::GameLoop &gameLoop);

            virtual void execute() const override;

        private:
            dc::engine::GameLoop &mGameLoop;
        };
    }
}

#endif //DUNGEONCRAWLER_NEWGAMECOMMAND_H
