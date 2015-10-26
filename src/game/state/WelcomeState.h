#ifndef WELCOMESTATE_H
#define WELCOMESTATE_H

#include "GameLoop.h"
#include "state.h"
#include "command.h"

namespace dc {
    namespace game {
        class WelcomeState : public engine::State {
        public:
            WelcomeState();

            void onInitialize(engine::GameLoop *game) override;

            void onEnter(engine::GameLoop *game) override;

            std::string onRead() override;

            engine::Command *onEval(std::string input) override;

            void onPrint(engine::GameLoop &game, engine::Command *command) override;

        private:
            std::string mWelcomeMsg;
        };
    }
}

#endif // WELCOMESTATE_H
