#include <iostream>
#include "util/Number.h"
#include "state/CombatState.h"
#include "CombatCommandManager.h"
#include "AttackCommand.h"
#include "FleeCommand.h"
#include "InventoryCommand.h"
#include "NullCommand.h"

CombatCommandManager::CombatCommandManager(CombatState &combatState) :
    mCombatState(combatState) {

}

dc::engine::Command *CombatCommandManager::create(std::vector<std::string> &inputs) const {
    const std::string &commandName = inputs.size() > 0 ? inputs[0] : "";
    if(commandName == "attack") {
        return createAttackCommand(inputs);
    } else if(commandName == "flee") {
        return new FleeCommand();
    } else if(commandName == "inv") {
        return new dc::game::InventoryCommand();
    } else if(commandName == "use") {
        // TODO: Use command
    } else {
        std::cout << "What are you doing?! Fight!" << std::endl;
        return new dc::game::NullCommand();
    }
}

dc::engine::Command *CombatCommandManager::createAttackCommand(std::vector<std::string> &inputs) const {
    if(inputs.size() != 2) {
        std::cout << "Not enough arguments" << std::endl;
        return new dc::game::NullCommand();
    }

    int mobNum = Number::toLong(inputs[1]);
    if(mobNum == -1) {
        std::cout << "Which monsters is that?!" << std::endl;
        return new dc::game::NullCommand();
    }

    dc::model::Mob *mob = mCombatState.mob(mobNum);
    if(mob == nullptr) {
        std::cout << "Which monster is that?" << std::endl;
        return new dc::game::NullCommand();
    }

    return new AttackCommand(*mob);
}
