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
#include "util/console.h"

CombatState::CombatState(dc::model::Game &game) :
        mCommandManager(*this),
        mGame(game) {

}

CombatState::~CombatState() {

}

void CombatState::onInitialize(dc::engine::GameLoop *game) {

}

void CombatState::onEnter(dc::engine::GameLoop *game) {
    std::cout << csl::color(csl::LIGHTRED) << "\nA group of enemies storm towards you." << csl::color(csl::GREY) << "\nYou prepare for battle." << std::endl;
}

std::string CombatState::onRead() {
    std::cout << csl::color(csl::RED) << "You are in combat!\n\n" << csl::color(csl::WHITE) << "In front of you stand:" << std::endl;

    // TODO: Show all enemies

    std::cout << csl::color(csl::GREEN) << "(" << "0" << "/" << "100" << ")" << csl::color(csl::GREY) << ">";

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
    command->execute();

    // execute enemies turn
}