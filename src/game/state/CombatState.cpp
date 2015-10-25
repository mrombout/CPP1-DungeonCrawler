#include <string>
#include <sstream>
#include <vector>
#include "Player.h"
#include "command/AttackCommand.h"
#include "command/InventoryCommand.h"
#include "command/LookCommand.h"
#include "GameplayState.h"
#include "CombatState.h"
#include "util/console.h"
#include "util/ServiceLocator.h"
#include "util/Render.h"

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

    dc::model::Game &game = ServiceLocator::getInstance().resolve<dc::model::Game>();
    Render::mobList(game.player().room().mobs());
    std::cout << "\n";

    std::cout << csl::color(csl::GREEN) << "(" << "0" << "/" << "100" << ")" << csl::color(csl::GREY) << ">";

    std::string input;

    std::getline(std::cin, input);

    return input;
}

dc::engine::Command *CombatState::onEval(std::string input) {
    // determine command
    dc::engine::Command *command = mCommandManager.create(input);

    return command;
}

void CombatState::onPrint(dc::engine::GameLoop &game, dc::engine::Command *command) {
    // execute player turn
    command->execute();

    // execute enemies turn
}