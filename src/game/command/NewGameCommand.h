#ifndef DUNGEONCRAWLER_NEWGAMECOMMAND_H
#define DUNGEONCRAWLER_NEWGAMECOMMAND_H

#include <GameLoop.h>
#include "CommandParameters.h"
#include "command.h"

namespace dc {
    namespace game {
        class NewGameCommand : public engine::Command {
        public:
            virtual void execute(engine::GameLoop &game) const override;
        };
    }
}

#endif //DUNGEONCRAWLER_NEWGAMECOMMAND_H
