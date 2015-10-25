#ifndef DUNGEONCRAWLER_NEWGAMECOMMAND_H
#define DUNGEONCRAWLER_NEWGAMECOMMAND_H

#include <GameLoop.h>
#include "CommandParameters.h"
#include "command.h"

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
