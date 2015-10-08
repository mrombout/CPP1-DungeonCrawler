#ifndef DUNGEONCRAWLER_GAMEPLAYSTATE_H
#define DUNGEONCRAWLER_GAMEPLAYSTATE_H

#include "state.h"

namespace dc {
    namespace engine {
        class Game;
    }
}

namespace dc {
    namespace game {
        class GameplayState : public engine::State {
        public:
            void onInitialize(engine::Game *game) override;
            void onEnter(engine::Game *game) override;
            std::string onRead() override;
            engine::Command *onEval(std::string input) override;
        };
    }
}


#endif //DUNGEONCRAWLER_GAMEPLAYSTATE_H
