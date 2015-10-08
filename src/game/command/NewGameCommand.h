#ifndef DUNGEONCRAWLER_NEWGAMECOMMAND_H
#define DUNGEONCRAWLER_NEWGAMECOMMAND_H

#include "CommandParameters.h"
#include "command.h"

namespace dc {
    namespace game {
        class NewGameCommand : public engine::Command {
        public:
            virtual void execute(engine::CommandParameters &parameters) const override;
        };
    }
}

#endif //DUNGEONCRAWLER_NEWGAMECOMMAND_H
