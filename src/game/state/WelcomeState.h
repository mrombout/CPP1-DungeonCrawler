#ifndef WELCOMESTATE_H
#define WELCOMESTATE_H

#include "GameLoop.h"
#include "state.h"
#include "command.h"

namespace dc {
    namespace game {
        class WelcomeState : public game::State {
        public:
            WelcomeState();

            void onInitialize(game::GameLoop *game) override;

            void onEnter(game::GameLoop *game) override;

            std::string onRead() override;

            game::Command *onEval(std::string input) override;

            void onPrint(game::GameLoop &game, game::Command *command) override;

        private:
            std::string mWelcomeMsg;
        };
    }
}

#endif // WELCOMESTATE_H
