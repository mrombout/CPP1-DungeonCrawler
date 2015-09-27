#ifndef WELCOMESTATE_H
#define WELCOMESTATE_H

#include <string>
#include <QString>
#include "Engine\game.h"
#include "Engine\state.h"
#include "Engine\command.h"

namespace dc {
namespace game {

    class WelcomeState : public engine::State<engine::Game>
    {
    public:
        WelcomeState();

        void onInitialize(engine::Game *game) override;
        void onEnter(engine::Game *game) override;
        std::string onRead() override;
        engine::Command *onEval(std::string input) override;

    private:
        QString mWelcomeMsg;
    };

}
}

#endif // WELCOMESTATE_H
