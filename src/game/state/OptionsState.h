#ifndef DUNGEONCRAWLER_OPTIONSSTATE_H
#define DUNGEONCRAWLER_OPTIONSSTATE_H

#include "state.h"

namespace dc {
    namespace model {
        class Game;
    }
}

namespace dc {
    namespace game {
        class OptionsState : public dc::game::State {
        public:
            OptionsState();
            ~OptionsState();

            void onInitialize(dc::game::GameLoop *game) override;
            void onEnter(dc::game::GameLoop *game) override;
            std::string onRead() override;
            dc::game::Command *onEval(std::string input) override;
            void onPrint(dc::game::GameLoop &game, dc::game::Command *command) override;
        };
    }
}

#endif //DUNGEONCRAWLER_OPTIONSSTATE_H
