#ifndef WELCOMESTATE_H
#define WELCOMESTATE_H

#include "game.h"
#include "state.h"
#include "command.h"

namespace dc {
namespace game {

    class WelcomeState : public engine::State
    {
    public:
        WelcomeState();

        void onInitialize(engine::Game *game) override;
        void onEnter(engine::Game *game) override;
        std::string onRead() override;
        engine::Command *onEval(std::string input) override;

    private:
        std::string mWelcomeMsg;
    };

}
}

#endif // WELCOMESTATE_H
