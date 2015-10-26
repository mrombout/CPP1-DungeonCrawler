#ifndef DUNGEONCRAWLER_FLEECOMMAND_H
#define DUNGEONCRAWLER_FLEECOMMAND_H

#include "GameLoop.h"
#include "command.h"
#include "GoToCommand.h"

namespace dc {
    namespace game {
        class FleeCommand : public dc::game::Command {
        public:
            FleeCommand(dc::game::GameLoop &gameLoop, dc::game::GoToCommand *command);
            ~FleeCommand();

            virtual void execute() const override;

            static FleeCommand *create(Parameters parameters);

        private:
            dc::game::GameLoop &mGameLoop;
            dc::game::GoToCommand *mGoToCommand;
        };
    }
}

#endif //DUNGEONCRAWLER_FLEECOMMAND_H
