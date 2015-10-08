#include "GameplayState.h"

namespace dc {
    namespace game {
        GameplayState::GameplayState() :
            mCommandManager() {

        }

        void GameplayState::onInitialize(engine::Game *game) {

        }

        void GameplayState::onEnter(engine::Game *game) {
            std::cout << "Entering Gameplay" << std::endl;
        }

        std::string GameplayState::onRead() {
            std::string input;
            std::cin >> input;
            return input;
        }

        engine::Command *GameplayState::onEval(std::string input) {
            return mCommandManager.create(input);
        }
    }
}