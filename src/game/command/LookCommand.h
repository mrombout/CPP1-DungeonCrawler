#ifndef DUNGEONCRAWLER_LOOKCOMMAND_H
#define DUNGEONCRAWLER_LOOKCOMMAND_H

#include "CommandParameters.h"
#include "command.h"

namespace dc {
    namespace game {
        class LookCommand : public engine::Command {
        public:
            LookCommand(dc::model::Player &player);
            virtual void execute() const override;

        private:
            dc::model::Player &mPlayer;
        };
    }
}


#endif //DUNGEONCRAWLER_LOOKCOMMAND_H
