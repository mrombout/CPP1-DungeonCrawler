#include <iostream>
#include "NewGameCommand.h"
#include "game.h"
#include "state/GameplayState.h"

namespace dc {
    namespace game {
        void NewGameCommand::execute(dc::engine::CommandParameters &parameters) const {
            std::cout << "Executing NewGameCommand" << std::endl;
            parameters.game().pushState(new GameplayState());
        }
    }
}
