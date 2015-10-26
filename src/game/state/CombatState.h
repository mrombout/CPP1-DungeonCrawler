#ifndef DUNGEONCRAWLER_COMBATSTATE_H
#define DUNGEONCRAWLER_COMBATSTATE_H

#include <vector>
#include "command/CombatCommandManager.h"
#include "Game.h"
#include "state.h"

namespace dc {
    namespace model {
        class Game;
    }
}

namespace dc {
    namespace game {
        class CombatState : public dc::game::State {
        public:
            CombatState(dc::model::Game &game);

            ~CombatState();

            void onInitialize(dc::game::GameLoop *game) override;
            void onEnter(dc::game::GameLoop *game) override;
            std::string onRead() override;
            dc::game::Command *onEval(std::string input) override;
            void onPrint(dc::game::GameLoop &game, dc::game::Command *command) override;

        private:
            const dc::game::CombatCommandManager mCommandManager;
            dc::model::Game &mGame;
        };
    }
}

#endif //DUNGEONCRAWLER_COMBATSTATE_H
