#ifndef DUNGEONCRAWLER_EXITCOMMAND_H
#define DUNGEONCRAWLER_EXITCOMMAND_H

#include "GameLoop.h"
#include "Game.h"
#include "command.h"

namespace dc {
    namespace game {
        class ExitCommand : public Command {
        public:
            ExitCommand(dc::game::GameLoop &gameLoop, dc::model::Game *game);

            virtual void execute() const;
            virtual bool isAction() const;

            static ExitCommand *create(Parameters &parameters);

        private:
            dc::game::GameLoop &mGameLoop;
            dc::model::Game *mGame;
        };
    }
}

#endif //DUNGEONCRAWLER_EXITCOMMAND_H
