#include <iostream>
#include "NewGameCommand.h"
#include "GameLoop.h"
#include "state/GameplayState.h"

namespace dc {
    namespace game {
        void NewGameCommand::execute(engine::GameLoop &game) const {
            std::cout << "Executing NewGameCommand" << std::endl;
            game.pushState(new GameplayState());
        }
    }
}
