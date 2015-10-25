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
        class GameplayState : public engine::State {
        public:
            GameplayState();
            ~GameplayState();

            void onInitialize(engine::GameLoop *game) override;
            void onEnter(engine::GameLoop *game) override;
            std::string onRead() override;
            engine::Command *onEval(std::string input) override;
            void onPrint(engine::GameLoop &game, engine::Command *command) override;

            void updateEnemies(engine::GameLoop &game) const;

        private:
            const CommandManager mCommandManager;
            model::Game *mGame;

            void springTraps(engine::GameLoop &loop);
        };
    }
}


#endif //DUNGEONCRAWLER_GAMEPLAYSTATE_H
