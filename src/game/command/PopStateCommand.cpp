#include <iostream>
#include "PopStateCommand.h"
#include "util/console.h"
#include "util/ServiceLocator.h"
#include "GameLoop.h"
#include "state.h"

namespace dc {
    namespace game {
        PopStateCommand::PopStateCommand(dc::game::GameLoop &gameLoop) :
                mGameLoop(gameLoop) {

        }

        void PopStateCommand::execute() const {
            csl::log() << "Executing PopStateCommand" << std::endl;
            dc::game::State *state = mGameLoop.popState();
            delete state;
        }

        PopStateCommand *PopStateCommand::create() {
            return new PopStateCommand(ServiceLocator::getInstance().resolve<dc::game::GameLoop>());
        }

        bool PopStateCommand::isAction() const {
            return false;
        }
    }
}
