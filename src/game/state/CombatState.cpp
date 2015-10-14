#include "GameplayState.h"
#include "command/NullCommand.h"
#include "CombatState.h"
#include "Game.h"

CombatState::CombatState() :
    mCommandManager() {

}

CombatState::~CombatState() {

}

void CombatState::onInitialize(dc::engine::GameLoop *game) {

}

void CombatState::onEnter(dc::engine::GameLoop *game) {
    std::cout << "You prepare for battle" << std::endl;
}

std::string CombatState::onRead() {
    std::cout << "(" << "0" << "/" << "100" << ")>";
    std::string input;
    std::cin >> input;
    return input;
}

dc::engine::Command *CombatState::onEval(std::string input) {
    dc::engine::Command *command = mCommandManager.create(input);
    if(!command) {
        std::cout << "What are you doing?! Fight!" << std::endl;
        // TODO: Cache this NullCommand
        return new dc::game::NullCommand();
    }

    return command;
}

void CombatState::onPrint(dc::engine::GameLoop &game, dc::engine::Command *command) {
    dc::engine::CommandParameters cp(game, mGame->player(), *this);
    command->execute(cp);
}
