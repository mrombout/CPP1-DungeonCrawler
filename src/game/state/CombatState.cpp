#include <string>
#include <sstream>
#include <vector>
#include "command/AttackCommand.h"
#include "command/FleeCommand.h"
#include "command/InventoryCommand.h"
#include "GameplayState.h"
#include "command/NullCommand.h"
#include "CombatState.h"
#include "Game.h"

CombatState::CombatState(dc::model::Game game, const std::vector<dc::model::Mob *> &mobs) :
        mCommandManager(*this),
        mGame(game),
        mMobs(mobs) {

}

CombatState::~CombatState() {

}

void CombatState::onInitialize(dc::engine::GameLoop *game) {

}

void CombatState::onEnter(dc::engine::GameLoop *game) {
    std::cout << "\n A group of enemies storm towards you.\nYou prepare for battle." << std::endl;
}

std::string CombatState::onRead() {
    std::cout << "You are in combat!\n\n" << "In front of you stand:" << std::endl;

    // TODO: Show all enemies

    std::cout << "(" << "0" << "/" << "100" << ") ";

    std::string input;

    std::getline(std::cin, input);

    return input;
}

dc::engine::Command *CombatState::onEval(std::string input) {
    // read inputs
    std::vector<std::string> inputs;
    std::stringstream ss(input);
    std::string item;
    while(ss >> item)
        inputs.push_back(item);

    // determine command
    dc::engine::Command *command = mCommandManager.create(inputs);

    return command;
}

void CombatState::onPrint(dc::engine::GameLoop &game, dc::engine::Command *command) {
    // execute player turn
    dc::engine::CommandParameters cp(game, mGame.player(), *this);
    command->execute(cp);

    // execute enemies turn

}

dc::model::Mob *CombatState::mob(unsigned int num) const {
    return mMobs[num];
}
