#ifndef DUNGEONCRAWLER_COMBATSTATE_H
#define DUNGEONCRAWLER_COMBATSTATE_H

#include "command/CommandManager.h"
#include "state.h"

namespace dc {
    namespace model {
        class Game;
    }
}

class CombatState : public dc::engine::State {
public:
    CombatState();
    ~CombatState();

    void onInitialize(dc::engine::GameLoop *game) override;
    void onEnter(dc::engine::GameLoop *game) override;
    std::string onRead() override;
    dc::engine::Command *onEval(std::string input) override;

    void onPrint(dc::engine::GameLoop &game, dc::engine::Command *command) override;

private:
    const dc::game::CommandManager mCommandManager;
    dc::model::Game *mGame;
};

#endif //DUNGEONCRAWLER_COMBATSTATE_H