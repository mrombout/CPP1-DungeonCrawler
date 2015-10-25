#include <iostream>
#include "NewGameCommand.h"
#include "GameLoop.h"
#include "state/GameplayState.h"
#include "util/console.h"

namespace dc {
    namespace game {
        NewGameCommand::NewGameCommand(dc::engine::GameLoop &gameLoop) :
                mGameLoop(gameLoop) {

        }

        void NewGameCommand::execute() const {
            csl::log() << "Executing NewGameCommand" << std::endl;
            mGameLoop.pushState(new GameplayState());
        }
    }
}
