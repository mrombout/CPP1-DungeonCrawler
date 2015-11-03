#include <Game.h>
#include "util/ServiceLocator.h"
#include "ExitCommand.h"
#include "GameLoop.h"

namespace dc {
    namespace game {
        ExitCommand::ExitCommand(dc::game::GameLoop &gameLoop, dc::model::Game *game) :
            mGameLoop(gameLoop),
            mGame(game) {

        }

        void ExitCommand::execute() const {
            if(mGame)
                delete mGame;
            mGameLoop.stop();
        }

        bool ExitCommand::isAction() const {
            return false;
        }

        ExitCommand *ExitCommand::create(Parameters &parameters) {
            ServiceLocator &sl = ServiceLocator::getInstance();
            return new ExitCommand(sl.resolve<dc::game::GameLoop>(), nullptr);
        }
    }
}