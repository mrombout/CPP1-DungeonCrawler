#ifndef DUNGEONCRAWLER_POPSTATECOMMAND_H
#define DUNGEONCRAWLER_POPSTATECOMMAND_H

#include "command.h"

namespace dc {
    namespace game {
        class GameLoop;
    }
}


namespace dc {
    namespace game {
        class PopStateCommand : public game::Command {
        public:
            PopStateCommand(dc::game::GameLoop &gameLoop);

            virtual void execute() const override;

            static PopStateCommand *create();

        private:
            dc::game::GameLoop &mGameLoop;
        };
    }
}

#endif //DUNGEONCRAWLER_POPSTATECOMMAND_H
