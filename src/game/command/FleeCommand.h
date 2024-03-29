#ifndef DUNGEONCRAWLER_FLEECOMMAND_H
#define DUNGEONCRAWLER_FLEECOMMAND_H

#include "GameLoop.h"
#include "command.h"
#include "GoToCommand.h"

namespace dc {
    namespace game {
        class FleeCommand : public dc::game::Command {
        public:
            FleeCommand(GameLoop &gameLoop, model::Player &player, GoToCommand *command);
            ~FleeCommand();

            virtual void execute() const override;
            virtual bool isAction() const;

            static FleeCommand *create(Parameters parameters);

        private:
            dc::game::GameLoop &mGameLoop;
            dc::game::GoToCommand *mGoToCommand;
            dc::model::Player &mPlayer;
        };
    }
}

#endif //DUNGEONCRAWLER_FLEECOMMAND_H
