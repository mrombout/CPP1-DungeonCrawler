#ifndef DUNGEONCRAWLER_LOOKCOMMAND_H
#define DUNGEONCRAWLER_LOOKCOMMAND_H

#include "CommandParameters.h"
#include "command.h"

namespace dc {
    namespace game {
        class LookCommand : public engine::Command {
            virtual void execute(engine::CommandParameters &parameters) const override;
        };
    }
}


#endif //DUNGEONCRAWLER_LOOKCOMMAND_H
