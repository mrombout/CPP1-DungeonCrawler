#ifndef DUNGEONCRAWLER_GAMEPLAYSTATE_H
#define DUNGEONCRAWLER_GAMEPLAYSTATE_H

#include "command/CommandManager.h"
#include "state.h"

namespace dc {
    namespace engine {
        class GameLoop;
    }
    namespace model {
        class Game;
    }
}

namespace dc {
    namespace game {
        class GameplayState : public game::State {
        public:
            GameplayState(dc::model::Game *game);
            ~GameplayState();

            void onInitialize(game::GameLoop *game) override;
            void onEnter(game::GameLoop *game) override;
            std::string onRead() override;
            game::Command *onEval(std::string input) override;
            void onPrint(game::GameLoop &game, game::Command *command) override;

            bool updateEnemies(game::GameLoop &game) const;

        private:
            const CommandManager mCommandManager;
            model::Game *mGame;
        };
    }
}


#endif //DUNGEONCRAWLER_GAMEPLAYSTATE_H
