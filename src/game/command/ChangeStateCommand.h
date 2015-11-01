#ifndef DUNGEONCRAWLER_CHANGESTATECOMMAND_H
#define DUNGEONCRAWLER_CHANGESTATECOMMAND_H

#include "state.h"
#include "command.h"

namespace dc {
    namespace game {
        class GameLoop;
    }
}

namespace dc {
    namespace game {
        class ChangeStateCommand : public game::Command {
        public:
            ChangeStateCommand(dc::game::GameLoop &gameLoop, State *state);

            virtual void execute() const override;
            virtual bool isAction() const;

            static ChangeStateCommand *create(State *state);

        private:
            dc::game::GameLoop &mGameLoop;
            State *mState;
        };
    }
}

#endif //DUNGEONCRAWLER_CHANGESTATECOMMAND_H
