#include <iostream>
#include "PopStateCommand.h"
#include "util/console.h"
#include "util/ServiceLocator.h"
#include "GameLoop.h"

namespace dc {
    namespace game {
        PopStateCommand::PopStateCommand(dc::game::GameLoop &gameLoop) :
                mGameLoop(gameLoop) {

        }

        void PopStateCommand::execute() const {
            csl::log() << "Executing PopStateCommand" << std::endl;
            mGameLoop.popState();
        }

        PopStateCommand *PopStateCommand::create() {
            return new PopStateCommand(ServiceLocator::getInstance().resolve<dc::game::GameLoop>());
        }
    }
}