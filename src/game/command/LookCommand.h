#ifndef DUNGEONCRAWLER_LOOKCOMMAND_H
#define DUNGEONCRAWLER_LOOKCOMMAND_H

#include "command.h"

namespace dc {
    namespace model {
        class Player;
    }
}

namespace dc {
    namespace game {
        class LookCommand : public engine::Command {
        public:
            LookCommand(dc::model::Player &player);
            virtual void execute() const override;

            static LookCommand *create(Parameters parameters);

        private:
            dc::model::Player &mPlayer;
        };
    }
}


#endif //DUNGEONCRAWLER_LOOKCOMMAND_H
