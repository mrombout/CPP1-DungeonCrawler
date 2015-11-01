#include <iostream>
#include <util/ServiceLocator.h>
#include <Game.h>
#include "ChangeStateCommand.h"
#include "util/console.h"
#include "GameLoop.h"

namespace dc {
    namespace game {
        ChangeStateCommand::ChangeStateCommand(dc::game::GameLoop &gameLoop, State *state) :
                mGameLoop(gameLoop),
                mState(state) {

        }

        void ChangeStateCommand::execute() const {
            csl::log() << "Executing ChangeStateCommand" << std::endl;
            mGameLoop.pushState(mState);
        }

        ChangeStateCommand *ChangeStateCommand::create(State *state) {
            return new ChangeStateCommand(ServiceLocator::getInstance().resolve<dc::game::GameLoop>(), state);
        }

        bool ChangeStateCommand::isAction() const {
            return false;
        }
    }
}

