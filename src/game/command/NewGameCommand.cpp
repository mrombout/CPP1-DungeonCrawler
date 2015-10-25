#include <iostream>
#include "NewGameCommand.h"
#include "GameLoop.h"
#include "state/GameplayState.h"
#include "util/console.h"

namespace dc {
    namespace game {
        void NewGameCommand::execute(engine::GameLoop &game) const {
            csl::log() << "Executing NewGameCommand" << std::endl;
            game.pushState(new GameplayState());
        }
    }
}
